#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
unsigned long long d;
vector<unsigned long long>x;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	long long ans=0;
	for(int i=1;i<=t;i++,x.clear(),ans=0){
		cin>>n>>d;
		unsigned long long xx;
		for(int i=1;i<=n;i++){
			cin>>xx;
			x.push_back(xx);			
		}				
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		if(n<4){
			cout<<0<<endl;
			continue;
		}		
		for(int i=0,j=i+3;i<=n-4;i++,j++){
			bool ok=1;
			if(x[j]-x[i]<=d){
				continue;
			}
			for(int z=i+1;z<=j;z++){
				
				if(x[z]-x[z-1]>d){
					ok=0;
					break;
				}
			}
			if(ok){
				ans+=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
