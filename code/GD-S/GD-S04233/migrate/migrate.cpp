#include<bits/stdc++.h>
using namespace std;
void migrate(){
	int n=0,d=0;
	bool s=0;
	cin>>n>>d;
	int a[n],ans[n][n];
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]<=d){
			s=1;
		}
	}
	if(s==0){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i][j]=0;
		}
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c>=1&&c<=10){
			migrate();
		}
	}
	return 0;
}
