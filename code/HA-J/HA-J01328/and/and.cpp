#include<bits/stdc++.h>
#define endl '\n'
#define getchar getchar_unlocked
#define int long long
using namespace std;
int n,m,a[200005];
long long ans;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dfs(int cnt,int last,int sum){
	if(sum==0)return;
	if(cnt==m){
		ans=(sum>ans?sum:ans);
		return;
	}
	for(register int i=last;i<=n;i++)
		dfs(cnt+1,i+1,sum&a[i]);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(register int i=1;i<=n;i++)
		a[i]=read();
	if(n==m){
		ans=a[1];
		for(register int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans<<endl;
	}
	if(m==1){
		for(register int i=1;i<=n;i++)
			ans=max(ans,(long long)a[i]);
		cout<<ans<<endl;
		return 0;
	}
	for(register int i=1;i<=n-m+1;i++)
		if(a[i]!=0)
			dfs(0,i,a[i]);
	cout<<ans<<endl;
	return 0;
}
//dp ²» •þ ß@ °Ñ ½o ÁË 
