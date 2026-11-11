#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c=0,t=0,n=0,d=0,e=0;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		long long a[n+10]={};
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		long long b=a[1]-a[0];
		long long e=d/b;
		if(e==0){
			cout<<0<<endl;
			return 0;
		} 
		else if(n-e*2+1<=0){
			cout<<0<<endl;
		}
		else cout<<n-e*2+1<<endl;
	}
}
