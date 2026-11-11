#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long a[maxn];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//É¾×¢ÊÍ
	int C,t_;cin>>C>>t_;
//	if(C<=6){
		while(t_--){
			int n,d;cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(n<4){
				cout<<"0\n";
				continue;
			}
			long long ans=0;
			for(int i=1;i<n-1;i++){
				for(int j=i+2;j<=n;j++){
					int cnt=0;
					for(int k=i+1;k<j;k++){
						if(cnt>=3)break;
						if(abs(a[k]-a[i])<=d&&abs(a[j]-a[k])<=d)cnt+=1;
					}
					if(cnt==2)ans+=1;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
//	}
	/*else if(C==11||C==12){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<4){
			cout<<"0\n";
			continue;
		}
		if(a[1]+d>=a[4])
	}*/
	return 0;
} 
