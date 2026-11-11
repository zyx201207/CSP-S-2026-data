#include<bits/stdc++.h>
using namespace std;
int a[5000001];
int n,d,ans=0;
void dp(int x,int y,int z,int cnt,bool f){
	if(f&&x==y){
		ans++;
		return;
	}
	if(x==y&&!f){
		f=1;
		return;
	}
	for(int i=1;i<=z;i++){
		dp(x,y-i,z,cnt,f);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		if(n<=3||d<=1){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				dp(i,j,d,0,0);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
