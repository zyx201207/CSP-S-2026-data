#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int x[2000005];
	int ans;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i>=n;i++){
			cin>>x[i];
		}
		if(d<=1){
			cout<<0<<endl;
			continue;
		}
		if((2*(x[2]-x[1])) > d){
			cout<<0<<endl;
			continue;
		}int xb=0;
		if(x[n]%x[1]==0){
			xb=(x[n]-x[1])/d;
		}else{
			xb=(x[n]-x[1])/d+1;
		}
		while(n>=2){
			ans+=(n-d-1);
			d--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
