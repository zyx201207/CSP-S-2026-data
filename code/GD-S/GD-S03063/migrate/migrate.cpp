#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0,sum=0;
		
		bool f=0;
		for(int i=1;i<n-1;i++){
			if(x[i+1]-x[i]!=x[i+2]-x[i+1]){
				f=1; 
				break;
			}
		}
	  	if(f==0){
			cout<<n-3<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					cnt++;
				}
				if(cnt==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
