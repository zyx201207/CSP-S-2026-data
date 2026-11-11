#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=4;i<=n;i++){
			cnt++;
		}
		cout<<cnt;
		cnt=0;
	}
	return 0;
} 
