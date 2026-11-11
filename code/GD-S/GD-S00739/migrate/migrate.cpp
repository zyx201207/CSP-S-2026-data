#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[5005][5005],cnt=0,C,K;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>K;
	while(K--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(m>2*(a[2]-a[1])){
			cout<<0;
			break;
		}
		else{
			cout<<n-m-1;
			break;
		}
	}
	return 0;
}
