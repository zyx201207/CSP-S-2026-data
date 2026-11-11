#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
    char bufin[1<<20],*fs,*ft;
    char getc(){
        return (fs==ft&&(ft=(fs=bufin)+fread(bufin,1,1<<20,stdin),fs==ft))?EOF:*fs++;
    }
    template<class T>
    void read(T& x){
        x=0;
        int f=1;
        char ch=getc();
        while(ch<'0'||ch>'9'){
            if(ch=='-') f=-1;
            ch=getc();
        }
        while(ch>='0'&&ch<='9'){
            x=10*x+(ch-'0');
            ch=getc();
        }
        if(f==-1) x=-x;
    }
}
using FastIO::read;
const int N=500005;
int n;
ll m;
ll a[N],pre[N];
ll w(int l,int r){
    return a[r]*(r-l+1)-(pre[r]-pre[l-1]);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    int res=0;
    for(int i=1,j=1;i<=n;i++){
        while(w(j,i)>m) ++j;
        res=max(res,i-j+1);
    }
    cout<<res<<endl;
}