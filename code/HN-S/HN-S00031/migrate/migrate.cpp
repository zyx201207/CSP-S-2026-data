#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,a[110000]={},sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j]-a[i]<d*2&&a[j]-a[i]>d){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
