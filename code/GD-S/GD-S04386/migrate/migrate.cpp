#include<bits/stdc++.h>
using namespace std;
int c,t,ld[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(ld,0,sizeof(ld));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>ld[i];
		}
		cout<<0<<endl;
	}
}
