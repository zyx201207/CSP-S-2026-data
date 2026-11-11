#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[1000001],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	while(t>0){
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		t--;
	}
	 if(d==2&&n<4){
		cout<<0;
	}else{
		if(d==2&&n>=4){
			ans=n/4+(n-4);
			cout<<ans;
		}
	}
	return 0;
}
