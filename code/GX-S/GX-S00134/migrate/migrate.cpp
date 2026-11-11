#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000009];
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(d<a[n]-a[n-2]){
			cout<<0<<endl;
		}
		else if(d>=a[n]-a[n-2]&&d<a[n]-a[n-3]){
			int k=n/(a[n]-a[n-1]);
			cout<<k-3<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	
return 0;
}
