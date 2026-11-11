#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,cnt=1;
int x[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=cnt;i<=n+cnt-1;i++){
			cin>>x[i];
		}
		int f=x[cnt+1]-x[cnt];
		if(d<2*f){
			cout<<"0\n";
		}else{
			int a=d/f;
			if(n+1-2*a<=0)cout<<"0\n";
			else cout<<n+1-2*a<<endl;
		}
		cnt+=n;
	}
	return 0;
}
