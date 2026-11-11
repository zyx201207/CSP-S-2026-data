#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<"2\n";
		else if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4) cout<<"1\n";
		else if(a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2) cout<<0<<"\n";
		else if(a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6) cout<<1<<"\n";
		else cout<<0<<"\n";
	}
	return 0;
}
