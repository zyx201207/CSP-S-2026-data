#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n,m;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
//	if(c==11||c==12){
		while(t--){
			cin>>n>>m;
			int num;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				if(i==2) num=x[2]-x[1];
			}
			int ans=0;
			for(int i=2;i<=m/num;i++){
				ans+=n-i-1;
			}
			cout<<ans<<endl;
		}
//	}
	return 0;
}

