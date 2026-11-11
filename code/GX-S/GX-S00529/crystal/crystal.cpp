#include <cstdio>
#include <algorithm>
#define lovelive long long
#if defined(__linux__) || defined(linux) || defined(__linux)
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

const int maxn = 5*114514;
lovelive a[maxn], b[maxn], m;
int n;
int read();
lovelive llread();
FILE *in = stdin, *out = stdout;

int main(){
    in = fopen("crystal.in", "r");out = fopen("crystal.out", "w");
    n = read(), m = llread();
    for(int i = 1; i <= n; ++i){
        a[i] = llread();
    }
    std::sort(a+1, a+1+n);
    for(int i = 1; i <= n; ++i){
        b[i] = a[i]+b[i-1];
    }
    //Why NOI Linux in this test doesn't suppport using Chinese to input?
    lovelive sum, maxn, honaka;
    int len, ans=1;
    int l=1;
    for(int r = 1; r <= n; ++r){
        maxn = a[r];
        len = r-l+1;
        honaka = maxn*len-(b[r]-b[l-1]);
        while(honaka > m){
            ++l;
            len = r-l+1;
            honaka = maxn*len-(b[r]-b[l-1]);
        }
        ans = std::max(ans, len);
    }
    fprintf(out, "%d", ans);
    return 0;
}

int read(){
    int ans = 0, f = 1;
    char ch = fgetc(in);
    while(ch < '0' or ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = fgetc(in);
    }
    while('0' <= ch and ch <= '9'){
        ans = ans*10+ch-'0';
        ch = fgetc(in);
    }
    return ans*f;
}
lovelive llread(){
    lovelive ans = 0, f = 1;
    char ch = fgetc(in);
    while(ch < '0' or ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = fgetc(in);
    }
    while('0' <= ch and ch <= '9'){
        ans = ans*10+ch-'0';
        ch = fgetc(in);
    }
    return ans*f;
}

//wo   zhi   dao~
//wo di wei lai bu shi meng
//wo zhen xi sheng huo mei yi fen zhong!
//wo di wei lai bu shi meng
//wo di xin gen zhe xi wang zai dong
//wo di wei lai bu shi meng
//wo zhen xi xian zai mei yi fen zhong
//wo di wei lai bu shi meng
//wo di xin gen zhe xi wang zai dong
//gen zhe xi wang zai dong...
//
//These lycris are written by Zhang Yusheng, a famous Chinese singer.
//The song is fantastic, it makes me powerful and positive to live.
