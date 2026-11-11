#include <cstdio>
#include <stdexcept>
#include <new>
#include <algorithm>
#define running_type 'C'

FILE* fin; FILE* fout;

typedef unsigned int u_int;
template<typename T>
class Array {
protected:
    T* _bg; T* _ed;
public:
    Array(void) : _bg(nullptr), _ed(nullptr) { }
    Array(u_int init_size, const T &v = T{}) : _bg(nullptr), _ed(nullptr) {
        if(init_size == 0) return ;
        _bg = new int[init_size]();
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

struct g {
    bool operator()(const int &a, const int &b) {
        return b < a;
    }
};

int main(void) {
    #if running_type == 'C'
        fin = fopen("and.in", "r"), fout = fopen("and.out", "w");
    #elif running_type == 'T'
        fin = stdin, fout = stdout;
    #endif
    int n, m;
    fscanf(fin, "%d %d", &n, &m);
    if(n == 1) {
        int tmp;
        fscanf(fin, "%d", &tmp);
        fprintf(fout, "%d", tmp);
    }
    Array<int> a(n+2);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        fscanf(fin, "%d", a.begin()+i);
    }
    std::sort(a.begin() + 1, a.end(), g());
    int ans = a[1];
    for (int i = 2; i <= m; ++i) {
        ans &= a[i];
    }
    fprintf(fout, "%d", ans);
    return 0;
}
