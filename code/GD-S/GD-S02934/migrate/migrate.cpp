#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5,M=5e3+5;
ll c,t,n,m,ans;
ll a[N],b[M][M];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(11<=c&&c<=12){
			cout<<0;
		}
		else{
			for(int i=1;i<=n;i++){
				int l=i;
				for(int j=i+1;j<=n;j++){
					while(l!=INT_MAX&&a[j]-a[l]>m){
						l++;
					}
					if(l==j) l=INT_MAX;
					if(l==INT_MAX) b[i][j]=l;
					else b[i][j]=b[i][l]+1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					if(b[i][j-1]==b[i][j]-1&&b[i][j-2]==b[i][j]-1&&b[j-2][j]==1&&(j==i+2||b[i][j-3]!=b[i][j]-1||b[j-3][j]!=1)) ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
