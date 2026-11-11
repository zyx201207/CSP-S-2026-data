#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10001];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		int q=0;
		for(int j=0;j<n;j++){
			for(int z=1;z<d;z++){
				if((a[n-1]-a[j])/z==0) q++;
			}
		}
		if(q>=2){
			cout<<q;
		}
		
	}
	








return 0;
}





