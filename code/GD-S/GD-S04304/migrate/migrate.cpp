#include <bits/stdc++.h>
using namespace std;
long long c,t,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+d;j<=n;j++){
				if(x[j]-x[i]==d+(d-1)){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;	
}
