#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[1000005];
bool f;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int dd=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=dd){
				f=1;
			}
		}
		if(f==0){
			cout<<2<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}
