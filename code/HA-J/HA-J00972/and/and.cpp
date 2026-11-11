#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010],dp[200010],maxx=-1;
bool b[200010];
void dfs(long long x,long long ans,long long s) {
	if (s==m) {
		//cout<<"#\n";
		maxx=max(maxx,ans);
		return ;
	}
	else {
		for (int i=1;i<=n;i++) {
			if (b[i]==0&&s<m) {
				long long l=ans;
				b[i]=1;
				ans=x&a[i];
				s++;
				//cout<<i<<" "<<a[i]<<" "<<s<<" "<<ans<<endl;
				dfs(ans,ans,s);
				//cout<<"$\n";
				b[i]=0;
				ans=l;
				s--;
			}
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		b[i]=1;
		//cout<<"!!!!!!!!!!!!"<<i<<"!!!!!!\n";
		dfs(a[i],0,1);
		memset(b,0,sizeof(b));
	}
	cout<<maxx;
	return 0;
}
