#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int sss=1;sss<=t;sss++){
		long long n,d,x[2000001]={},a[2000001]={};
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<"0"<<endl;
			continue;
		}
		int bj,pd=0;
		for(int i=1;i<=n;i++){
			if(x[1]+d<x[i]){
				bj=i-1;
				//cout<<bj<<endl;
				pd=1;
				break;
			}
			
		}
		if(pd==0){
			cout<<"0"<<endl;
			continue;
		}
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++){
				a[j]++;
			}
		}
		long long z=0;
		for(int i=bj+1;i<=n;i++){
			if(a[i]==2){
				//cout<<x[i]<<endl;
				z++;
			}
		}
		cout<<z<<endl;
	} 
} 
