#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int x1,x2,dd;
		cin>>x1>>x2;
		dd=x2-x1;
		for(int i=3;i<=n;i++){
			cin>>x2;
		}
		if(d/2==dd&&x1+d<x2) cout<<n-3<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
