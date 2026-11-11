#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define req(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        x=(x<<1)+(x<<3)+c-48;
        c=getchar();
    }
    return f*x;
}
const int N=5e5+5;
int n,m;
int a[N],s[N];
int ch(int len){
	int mi=INT_MAX;
	rep(i,len,n){
		int x=a[i]*len-s[i]+s[i-len];
		mi=min(mi,x);
	}
	return mi;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    rep(i,1,n){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    rep(i,1,n)s[i]=s[i-1]+a[i];
    //rep(i,1,n)printf("%lld ",s[i]);
    //printf("\n");
    int l=1,r=n+1;
    while(r-l>1){
        //cout<<l<<"-"<<r<<endl;
		int mid=(l+r)>>1;
		int k=ch(mid);
		if(k==m){
			printf("%lld\n",mid);
			return 0;
		}
		if(k<=m)l=mid;
		else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}
