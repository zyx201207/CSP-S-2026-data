#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll n=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') n=n*10+c-'0',c=getchar();
	return n*f;
}
const int N=5e5+5;
int n;
ll a[N],s[N];
ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int r=1,l=1;r<=n;r++){
		while(l<=r && a[r]*(r-l+1)-(s[r]-s[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);

	return 0;
}
