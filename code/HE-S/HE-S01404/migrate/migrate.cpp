#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int> land;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;land.resize(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>land[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(land[j]-land[j-1]>d){
					break;
				}
				if((land[j]-land[i])%d==d-1&&(land[j]-land[i])>d){
					ans++; 
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
