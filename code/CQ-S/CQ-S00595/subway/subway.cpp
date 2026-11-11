#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct node{
	int zhan,bu;
}b[500005];
int l[505][500005];
vector<int> r[500005];
int p[505][505];//线的关系 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(p,0x3f,sizeof(p));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>b[j].zhan>>b[j].bu;
			l[i][b[j].zhan]=b[j].bu;
			r[b[j].zhan].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:r[i]){
			for(auto k:r[i]){
				if(j!=k){
					p[j][k]=p[k][j]=min(p[j][k],min(p[k][j],l[j][i]+l[k][i]));
				}
			}
		}
	} 
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<p[i][j]<<" "<<i<<" "<<j<<endl;
		}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j){
					p[i][j]=0;
				}else{
					p[i][j]=min(p[i][k]+p[k][j],p[i][j]);
				}
			}
		}
	}
	while(q--){
		int ll,rr;
		cin>>ll>>rr;
		int ans=INT_MAX;
		for(auto i:r[ll]){
			for(auto j:r[rr]){
				//cout<<i<<" "<<j<<" "<<p[i][j]<<" "<<a[ll]<<" "<<a[rr]<<" "<<l[i][ll]<<" "<<l[j][rr]<<endl;
				int u=0;
				u+=a[ll];
				u+=a[rr];
				u+=l[i][ll];
				u+=l[j][rr];
				u+=p[i][j];
				ans=min(ans,u);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
