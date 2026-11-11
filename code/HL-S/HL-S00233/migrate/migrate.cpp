#include<bits/stdc++.h>
using namespace std;
long long a[5001],d;
int firstfly[5001],secondfly[5001],refly[5001];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>d;
		if(n>5000){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			firstfly[i]=lower_bound(a+1,a+n+1,a[i]+d)-a;
			secondfly[i]=lower_bound(a+1,a+n+1,a[firstfly[i]]+d)-a;
			refly[i]=lower_bound(a+1,a+n+1,a[i]-d)-a; 
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			//int firstfly=lower_bound(a+1,a+n+1,a[i]+d)-a;
			//int secondfly=lower_bound(a+1,a+n+1,a[firstfly]+d)-a;
			//if(firstfly[i]+1-refly[firstfly[i]+1]==2) ans++; 
			for(int j=firstfly[i]+1;j<=secondfly[i];j++){
				//int refly=lower_bound(a+1,a+n+1,a[j]-d)-a; 
				if(j-refly[j]==2&&refly[j]!=firstfly[i]) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//how ccf make yl
//i cannot make n^2,i'm qu

