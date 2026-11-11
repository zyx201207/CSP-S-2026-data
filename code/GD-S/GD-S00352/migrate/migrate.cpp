#include<bits/stdc++.h>
using namespace std;
int ri(){
	int ans=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar()){}
	for(;isdigit(c);c=getchar())	ans=ans*10+(c^48);
	return ans;
}
long long a[2000010];
void solve(){
	int n=ri(),m=ri();
	for(int i=1;i<=n;i++){
		a[i]=ri();
	}
	sort(a+1,a+1+n);
	a[n+2]=-114514;
	int ans=0;
	for(int i=1;i<n;i++){
		if(a[i+2]-a[i]<=m&&a[i+3]-a[i]>m)	ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int p=ri(),t=ri();
	while(t--)	solve();
	return 0;
} 
