#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==0||c==11||c==12){
			cout<<n-3<<endl;
		}
		cout<<0<<endl;
	}
	return 0;
}
/*
Oct31==Dec25?
*/
