#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int a[MAXN],isA=1,c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		if(n<=3) cout<<0<<'\n';
		for(int i=1;i<=n;i++) cin>>a[i],isA=(i<=2?1:a[i]-a[i-1]==a[i-1]-a[i-2]);
		if(isA){
			int len=d/(a[2]-a[1]);
			if(len==1) cout<<0<<'\n';
			else cout<<n-(len+2)+1<<'\n';
			continue;
		}
		for(int i=1;i<n-1;i++) for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) continue;
			int cnt=0;
			for(int k=i+1;k<j;k++) if(a[k]-a[i]<=d&&a[j]-a[k]<=d)
				cnt++;
			ans+=(cnt==2);
		} cout<<ans<<'\n';
	} return 0;
}
