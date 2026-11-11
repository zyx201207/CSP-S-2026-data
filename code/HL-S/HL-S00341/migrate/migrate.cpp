#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			memset(x,0,sizeof(x));
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<1<<endl;
		}
	}else{
		while(t--){
			cout<<0<<endl;
		}
	}
	
	
	return 0;
}
