#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	long long x[10000];
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
	}
	for(int i=0;i<n;i++){
		if(n==2||n==1){
			cout<<0<<endl;
			return 0;
		}
		else if(a[i+1]-a[i]>d){
			cout<<0<<endl;
			return 0;
		}
		else if(a[i+1]-a[i]==1&&d==2){
			cout<<0<<endl;
			return 0;
		}
	}
	return 0;
}
