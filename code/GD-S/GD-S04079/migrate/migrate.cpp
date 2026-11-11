#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		vector<int> ve(n+1);
		for(int j=1;j<=n;j++){
			cin>>ve[j];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bool bo=1;
				int lon=ve[j]-ve[i];
				if(lon<=(j-i)*d)bo=1;
				
				else bo=0;
				if(bo){
					int cnt=0;
					for(int k=i+2;k<=j;k++){
						if(ve[k]-ve[i]<=d){
							
							cnt++;
						
							
						}
					}
					
				if(cnt>=2)ans++;	
				}
			}
			
		}	
		cout<<ans<<'\n';
	}
	return 0;
}
