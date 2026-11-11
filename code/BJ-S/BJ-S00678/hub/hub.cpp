#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

namespace IO{
    struct INID{INID(){ios::sync_with_stdio(false);cin.tie(nullptr);}};
    int gc(){return cin.rdbuf()->sbumpc();}
    void pc(char c){cout.rdbuf()->sputc(c);}
    template<typename T>void rd(T &x){
        x=0;int f=1,c=gc();
        while('0'>c||c>'9'){
            if(c==EOF){cerr<<"IIE";exit(0);}
            if(c=='-'){f*=-1;}
            c=gc();
        }
        while('0'<=c&&c<='9'){
            x=x*10+c-'0';
            c=gc();
        }
        x*=f;
    }
    template<typename T>void wt(T x){
        if(x<0){pc('-');}
        static int stk[40],tp,d;
        tp=0;
        do{
            d=x%10;
            stk[++tp]=(d<0?-d:d)+'0';
            x/=10;
        }while(x);
        while(tp){pc(stk[tp--]);}
    }
}using namespace IO;

#define int long long

constexpr int N=5e3+6;
constexpr int M=N*N;
constexpr int inf=0x3f3f3f3f3f3f3f3f;

int c,n,k;

void global(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    rd(c);
}

int len1,len2,len3;

namespace tqy{
    void init(){
        rd(n),rd(k);
        
    }   
    void solve(){
        k-=2;
        len1=len2=len3=(n-2)/3;
        if((n-2)%3>=1){
            len1++;
        }if((n-2)%3>=2){
            len2++;
        }
        int get=k/3;
        len1-=get;
        len2-=get;
        len3-=get;
        if(k%3>=1){
            len1--;
        }
        if(k%3>=2){
            len2--;
        }
        len1=max(0ll,len1);
        len2=max(0ll,len2);
        len3=max(0ll,len3);
        wt(max(max(len1,len2),len3));
        pc('\n');
    }
}

signed main(){
    global();
    int T=1;rd(T);
    while(T--)tqy::init(),tqy::solve();
    return 0;
}

/*



*/