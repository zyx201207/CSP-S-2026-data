#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[500005],d,dp[500005],g[500005],f;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long cnt=0ans;
		f=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i] = s[i-1]+a[i];
		}
		a[1]=0;
		for(int i=2;i<=n-2;i++){
			if(s[i]-s[i-1]>d || (s[i+2]-s[i-1]<=d && i !=n-1)){
				dp[i]=0;
				continue;
			}
			else if(s[i]-s[i-1]<=d && s[i+1]-s[i-1]>d)dp[i] = d[i-1]+1;
			else if(a[i+1]-s[i-1]<=d){
				g[++cnt] = i;
			}
		}
		if(cnt<2) cout<<0<<'\n';
		else {
			int i=1,j=1;
			while(i<cnt){
				int a=1,b=1,c=1;
				j=g[i];
				while(a[g[i+j]]-a[g[i+j-1]] <= d && a[g[i+1+j]]-a[g[i-1]]>d && i+j>1){
					j--;
					a++;
				}
				j=1;
				for(int j=1;j+a[g[i]]<a[g[i+1]];j++){
					if(a[g[i]+j]-a[g[i]+j-1]<=d && a[g[i]+j])
				}
			}
		}

	}
	cout<<a[1]<<g[1];
	return 0;
}
