#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int x,c=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				x=a[i]-a[i-1];
			}
			if(i>2){
				if(a[i]-a[i-1]!=x){
					c=1;
				}
			}
		}
		if(c==1||d<=x){
			cout<<'0'<<'\n';
			continue;
		}
		int y=d/x*2;
		if(y>n){
			cout<<'0'<<'\n'; 
			continue; 
		}
		cout<<n-y+1<<'\n';
	}
	return 0;
}
