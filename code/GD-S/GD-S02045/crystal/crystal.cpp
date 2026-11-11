#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5e5+10;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
int a[maxn],pre[maxn],n,m; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=1,ans=0;
	for(int r=1;r<=n;r++){
		while((r-l)*a[r]-(pre[r-1]-pre[l-1])>m){l++;}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
