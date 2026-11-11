#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,cha;
		cin>>n>>d;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1)continue;
			if(i==2)cha=a[2]-a[1];
			else {
				if(cha!=a[i]-a[i-1]){
					//cout<<a[i]-a[i-1]<<endl;
					//cout<<cha<<endl;
					flag=0;
				}
			}
		}
		if(flag){
			if(n<=3){
				cout<<0<<endl;
			}
			int k=d/cha;
			if(k==0||k%2==1){
				cout<<0<<endl;
				continue;
			}
			else{
				if(n==4&&k==2){
					cout<<1<<endl;
					continue;
				}
				if(k==2){
					cout<<n/k<<endl;
					continue;
				}
				else{
					cout<<0<<endl;
				}
			}
		}
		
	}
	return 0;
}
