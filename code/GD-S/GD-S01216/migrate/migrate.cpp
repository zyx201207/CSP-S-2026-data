#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cha=a[2]-a[1];
	int k=d/cha;
	if(k==0||k==1||k>=n){
		cout<<0<<endl;
	}else{
		cout<<n-2*k+1<<endl;
	}
	}
	return 0;
}
