#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[20000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		cin>>a[i];
		int t=d/(a[2]-a[1]);
		if(t!=2){
			cout<<0<<endl;
		}
		else{
			if(n<4) cout<<0<<endl;
			else
			cout<<n-3<<endl;
		}
	}
}
