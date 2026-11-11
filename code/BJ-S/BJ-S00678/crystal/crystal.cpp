#include<iostream>
#include<algorithm>

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

constexpr int N=5e5+5;

int n,m;
int a[N];
int q[N];
int ans;
int sum;

int calc(int i,int x){
    return x-a[i];
}

void global(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}

namespace tqy{
    void init(){
        rd(n),rd(m);
        for(int i=1;i<=n;++i){
            rd(a[i]);
        }
        sort(a+1,a+1+n);
    }   
    void solve(){
        int l=1,r=1;
        q[1]=a[1];
        ans=1;
        sum=0;
        while(r<=n){
            while(l+1<=r&&sum>m){
                sum-=calc(l,a[r]);
                ++l;
            }
            ans=max(ans,r-l+1);
            // cerr<<l<<' '<<r<<endl;
            while(r+1<=n&&sum+(r-l+1)*(a[r+1]-a[r])<=m){
                sum+=(r-l+1)*(a[r+1]-a[r]);
                ++r;
            }
            ans=max(ans,r-l+1);
            // cerr<<l<<' '<<r<<endl;
            sum+=(r-l+1)*(a[r+1]-a[r]);
            r=r+1;
        }
        wt(ans),pc('\n');
    }
}

signed main(){
    global();
    int T=1;
    while(T--)tqy::init(),tqy::solve();
    return 0;
}

/*
g++ 1.cpp -o 1 -Wall -fsanitize=leak,address,undefined
*/