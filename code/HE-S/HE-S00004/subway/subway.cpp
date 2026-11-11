#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q,w[10005],k[10005],a[1005][1005],t[1005][1005];
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	while(q--){
		int ans=0,x,y;
		cin>>x>>y;
		for(int i=0;i<n;i++){
			for(int j=0;j<k[i];j++){
				if(a[i][j]==x){
					ans=w[x]+t[i][j];
					x=a[i][j+1];
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
