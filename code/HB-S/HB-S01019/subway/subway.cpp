#include <bits/stdc++.h>
using namespace std;
const int N=2e4+7;
int w[N],a[N][520],t[N][520];
int c,n,m,d,k,q,j;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(n--){
		j++;
		cin>>k;
		for(int i=1;i<=k;i++){
				cin>>a[j][i]>>t[j][i];
		}
	}
	while(q--){
			int x,y;
			long long sum=0;
			cin>>x>>y;
			int r=max(x,y),l=min(x,y);
			for(int i=1;i<=n;i++){
				int ans=0;
				for(int j=1;j<=k;j++){
					if(a[i][j]==l||a[j][i]==r){
						ans++;	
					}
				}
				if(ans==2){
					for(int z=l;z<=r;z++){
						sum+=t[z][i];
					}
				}
			}
			cout<<sum<<endl;
	}
	return 0;
}
