#include <cstdio>
#include <stdexcept>
#include <new>
#define running_type 'C'

typedef unsigned int u_int;
template<typename T>
class Array {
protected:
    T* _bg; T* _ed;
public:
    Array(void) : _bg(nullptr), _ed(nullptr) { }
    Array(u_int init_size, const T &v = T{}) : _bg(nullptr), _ed(nullptr) {
        if(init_size == 0) return ;
        _bg = new T[init_size]();
        _ed = _bg + init_size;
        for(u_int i = 0; i < init_size; ++i) {
            _bg[i] = v;
        }
    }
    Array(const Array &o) : _bg(nullptr), _ed(nullptr) {
        if(&o == this || o.empty()) return ;
        u_int sz = o._ed - o._bg - 1;
        while(sz >= 0) {
            _bg[sz] = o._bg[sz];
        }
        _ed = _bg + sz;
    }
    Array(Array &o) : _bg(nullptr), _ed(nullptr) {
        if(&o == this || o.empty()) return ;
        u_int sz = o._ed - o._bg - 1;
        while(sz >= 0) {
            _bg[sz] = o._bg[sz];
        }
        _ed = _bg + sz;
    }
    Array operator=(const Array &o) {
        if(&o == this || o.empty()) return *this;
        u_int sz = o._ed - o._bg - 1;
        while(sz >= 0) {
            _bg[sz] = o._bg[sz];
        }
        _ed = _bg + sz;
    }
    bool empty(void) {
        return _bg == _ed;
    }
    const bool empty(void) const {
        return _bg == _ed;
    }
    u_int size(void) {
        return _ed - _bg;
    }
    const u_int size(void) const {
        return _ed - _bg;
    }
    void resize(u_int new_size, const T& v = T{}) {
        if(new_size == 0 || this->size() == new_size) return ;
        T* new_bg = new T[new_size]();
        for(u_int i = size(); i >= 0; --i) {
            new_bg[i] = _bg[i];
        }
        delete[] _bg;
        _bg = new_bg;
        _ed = _bg + new_size;
    }
    T& operator[](u_int idx) {
        if(idx >= this->size()) throw std::out_of_range("Bad index");
        return _bg[idx];
    }
    T* begin(void) { return _bg; }
    const T* begin(void) const { return _bg; }
    T* end(void) { return _ed; }
    const T* end(void) const { return _ed; }
    ~Array(void) noexcept {
        delete[] _bg;
    }
};

FILE* fin; FILE* fout;
Array<int> a;

template<typename Iterator, typename T>
u_int count(Iterator begin, Iterator end, const T& v) {
    u_int ans = 0;
    for(; begin != end; ++begin) {
        if(*begin == v) ++ans;
    }
    return ans;
}

template<typename Iterator, typename T>
int find(Iterator begin, Iterator end, const T& v) {
    while(begin != end) {
        if(*begin == v) return end - begin;
        ++begin;
    }
    return -1;
}

Array<int> solve(int n, int m, int i) {
    Array<int> desk(m+2), cur(a); // cards on the desk, Z's cards
    u_int real_sz = 1U;
    int tmp;
    while(i <= n) {
        int& k = cur[i];
        if((tmp = find(desk.begin(), desk.end(), k)) == -1) {
            desk[real_sz++] = k;
        } else {
            for(int i = tmp; i <= real_sz; ++i) {
                desk[i] = 0;
            }
            real_sz = tmp;
        }
    }
    return desk;
}

int main(void) {
    #if running_type == 'C'
        fin = fopen("card.in", "r"), fout = fopen("card.out", "w");
    #elif running_type == 'T'
        fin = stdin, fout = stdout;
    #endif
    int n, m;
    fscanf(fin, "%d %d", &n, &m);
    a.resize(n+2);
    for(int i = 1; i <= n; ++i) {
        fscanf(fin, "%d", a.begin()+i);
    }
    Array<u_int> ans(m+2, 0);
    for(int i = 1; i <= m; ++i) {
        Array<int> cur = solve(n, m, i);
        for(int j = 1; j <= m; ++j) {
            ans[i] += count(cur.begin(), cur.end(), j);
        }
    }
    for(auto bg = ans.begin(), ed = ans.end(); bg != ed; ++bg) {
        printf("%u ", *bg);
    }
    return 0;
}
