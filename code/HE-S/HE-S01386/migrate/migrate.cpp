#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,a[2000002],sum=0;
	cin>>c>>t;
	for(int m=1;m<=t;m++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[n-i+1]-a[1]>d){
				if((a[n-i+1]-a[1])/d>1){
					sum++;
				}
			}else{
				break;
			}
		}		
		cout<<sum<<endl;
		sum=0;
	}
	cout<<"p";
	return 0;
}
