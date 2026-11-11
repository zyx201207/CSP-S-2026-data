#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,a[105][1000005],n[105],d[105];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=t;i++){
		if(a[i][n[i]]+a[i][1]==0){
			cout<<0<<endl;
		}else if(a[i][1]<=0){
			cout<<(a[i][n[i]]+a[i][1])/2<<endl;
		}else{
			int x=(a[i][n[i]]+a[i][1])/2;
			cout<<x-1<<endl;
		}
	}
	return 0;
} 

