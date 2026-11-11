#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p,m1[1001]={0},k1[1001]={0},a[501][101]={0},x,y,ans=0,q=0;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>m1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k1[i];
		for(int j=1;j<=2*k1[i];j+=2){
			cin>>a[i][j]>>a[i][j+1];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>x>>y;
		ans=q=0;
		for(int j=1;j<=n;j++){
			q=0;
			for(int w=1;w<=2*k1[i];w+=2){
				if((a[j][w]==x||a[j][w]==y) && ans!=a[j][w+1]){
					q++;
					ans+=a[j][w+1];
					//cout<<a[j][w+1]<<endl;
				}
				if((a[j][w]==x||a[j][w]==y) && ans!=a[j][w+1]){
					q++;
					ans+=a[j][w+1];
					//cout<<a[j][w+1]<<endl;
				}
				if(q==2){
					break;
				}
			}
			if(q==2){
				ans+=m1[x];
				ans+=m1[y];
				cout<<ans<<endl;
				break;
			}
		}
	}
	return 0;
}
