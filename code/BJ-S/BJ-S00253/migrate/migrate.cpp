#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],sum;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==1||d>=a[n]-a[1]){
			cout<<0<<endl;
			continue;
		}
		sum=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]!=1 && (a[j]-a[i])%d==d-1){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}	
