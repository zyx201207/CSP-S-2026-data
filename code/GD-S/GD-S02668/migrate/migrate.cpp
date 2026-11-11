#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		int isl[n+1];
		for(int i=1;i<=n;i++){
			cin>>isl[i];
		}
		for(int i=1;i+3<=n;++i){
		if(((isl[i+3]-isl[i])>=d)&&((isl[i+3]-isl[i])<2*d)){	
			ans++;
			}
		}
		cout<<ans<<endl;
	}
}
