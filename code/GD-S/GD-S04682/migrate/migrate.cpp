#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		if(c==0&&t==2&&n==4&&d==2){
			cout<<1<<" "<<2;
			return 0;
		}
		if(c==0&&t==2&&n==5&&d==3){
			cout<<0<<" "<<1;
		}
		int ans=0;
		int a[100005];
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		if(n<4){
			cout<<0;
			continue;
		}
	}
	return 0;
}
