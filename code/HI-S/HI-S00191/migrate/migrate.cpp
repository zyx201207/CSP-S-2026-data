#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int p=x[2]-x[1],flag=0;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=p){
				flag=1;
				break;
			}
		}
		if(flag==0) cout<<n-1;
	}
	return 0;
}
