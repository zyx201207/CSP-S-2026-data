#include<bits/stdc++.h>
using namespace std;
int c,T,n,d;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		bool p=1;
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=abs(a[2]-a[1]);
		for(int i=1;i<n;i++){
			if(abs(a[i+1]-a[i])!=sum){
				p=0;
				break;
			}
		}
		if(p){
			if(sum>d){
				cout<<"0"<<endl;
				continue;
			}else{
				int sum2=0;
				for(int i=4;i<=n;i++){
					sum2++;
				}
				cout<<sum2<<endl;
				continue;
			}
		}
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(abs(a[i]-a[i+1])<d&&abs(a[i]-a[i+2])<d&&abs(a[j]-a[i+1])<d&&abs(a[j]-a[i+2])<d){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
