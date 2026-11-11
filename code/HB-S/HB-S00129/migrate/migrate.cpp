#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d,x[2000005];
void solve(){
	int a=d/(x[2]-x[1]);
	if(a==1){
		cout<<0;
		return;
	}
	long long ans=0;
	for(int i=a+2;i<min(n+1,2*a+1);i++)
		ans+=min(n+1,2*a+1)-1-i+1;
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool flag=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2]) flag=1;
		}	
		if(!flag) solve();
	}
	return 0;
}
