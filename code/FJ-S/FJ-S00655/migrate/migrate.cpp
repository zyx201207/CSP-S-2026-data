#include<bits/stdc++.h>
using namespace std;
long long w[2000001],lk;
long long cha[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,s=0,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>w[i];
			cha[i]=w[i]-s;
			s=w[i];
		}
		for(int i=1;i<=n;i++){
			int yo=0;
			for(int j=i+1;j<=n;j++){
				lk=(w[j]-w[i])%d;
				for(int k=i+1;k<=j;k++){
					if(cha[k]==lk)
					yo++;
				}
			}
				if(yo>=2){
					ans++;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
