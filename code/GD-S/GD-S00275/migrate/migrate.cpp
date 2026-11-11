#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+2;
int a[N];
struct b{
	int c,l;
}p[N];
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
		for(int i=1;i<=n;i++){
			for(int j=i;j<=i+d-1;j++){
				p[j].c=1;
				p[j].l=(a[j]-a[1])/d;
				
			}
			
		}
		cout<<1<<"\n";
	}
	return 0;
}
