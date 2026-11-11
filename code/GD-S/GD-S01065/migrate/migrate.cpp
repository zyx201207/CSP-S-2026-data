#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000220],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	bool f;
	cin>>c>>t>>n>>d;
	while (t--){
		cin>>n>>d;
		ans=0;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		if (f){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
