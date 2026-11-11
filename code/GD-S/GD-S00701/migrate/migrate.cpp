#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t;
int n;
ll d;
ll a[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
			
			int r=1;
			int ans=0;
			for(int l=1;l<=n;l++){
				while(r<n and a[r]-a[l]<=d){
					r++;
				}
				if(a[r]-a[l]<d*2 and r-l+1>=4){
					if(d-(a[r]-a[l]-d)==1){
						ans++;
//						cout<<l<<" "<<r<<"\n";
						for(int i=l-1;i>=1;i--){
							if(a[i+1]-a[i]<=d and a[i+2]-a[i]>d){
								ans++;
							}else{
								break;
							}
						}
						for(int i=r+1;i<=n;i--){
							if(a[i]-a[i-1]<=d and a[i]-a[i-2]>d){
								ans++;
							}else{
								break;
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
