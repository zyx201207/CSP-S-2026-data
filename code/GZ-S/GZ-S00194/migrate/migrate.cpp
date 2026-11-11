//GZ-S00194 周润泽 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		int a[n+7];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n%2==0)cout<<n/d-1<<'\n';
		else cout<<n/d+1<<'\n';
	}
	return 0;
}
