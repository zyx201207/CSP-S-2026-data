#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		int a[5005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n-d;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int k=1;k<=d;k++){
					if(a[i]+k==a[j]){
						cnt++;
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans;
		memset(a,0,sizeof(a));
		ans=0;
	}
	
	return 0;
} 
