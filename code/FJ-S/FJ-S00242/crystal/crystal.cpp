#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll n,m,a[N];
inline ll read(){
	ll x=0,k=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')k=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return k*x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	ll maxv=a[1],sum=0;int ans=0;
	for(int l=1,r=1;l<=n;++l){
		if(l!=1)sum-=maxv-a[l];
		while(sum<=m){
			if(r==n)break;
			++r;
			if(a[r]>maxv){
				ll d=a[r]-maxv;maxv=a[r];
				sum+=(r-l)*d;
			}
		}
		ans=max(ans,r-l);			
	}
	printf("%d",ans);
}
