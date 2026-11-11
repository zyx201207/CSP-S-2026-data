#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct zhd{
	int wi,ti,id;
};
struct xl{
	int ki;
	vector<zhd> vi;
	set<int> s;
	void change_size(int ki){
		vi.resize(ki);
	}
}a[505];
int mp[1005][1005];
bool flag[1005][1005];
int val[1005][1005];//在第i条路线上，第j个需要的 
int vis[1005][1005];//在ij在第k条路线上 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			mp[i][j]=2147483647;
		}
	}
	for(int i=0;i<m;i++){
		cin>>mp[i][i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].ki;
		a[i].change_size(a[i].ki);
		for(int j=0;j<a[i].ki;j++){
			cin>>a[i].vi[j].id>>a[i].vi[j].ti;
			a[i].s.insert(a[i].vi[i].id);
			a[i].vi[j].wi=mp[a[i].vi[j].id-1][a[i].vi[j].id-1];
			if(j>0){
				mp[a[i].vi[j].id-1][a[i].vi[j-1].id-1]=min(mp[a[i].vi[j].id-1][a[i].vi[j-1].id-1],a[i].vi[j-1].ti+a[i].vi[j].ti);
				mp[a[i].vi[j-1].id-1][a[i].vi[j].id-1]=mp[a[i].vi[j].id-1][a[i].vi[j-1].id-1];
				val[i][a[i].vi[j].id-1]=a[i].vi[j].ti;
				flag[a[i].vi[j].id-1][a[i].vi[j-1].id-1]=true;
				vis[a[i].vi[j].id-1][a[i].vi[j-1].id-1]=i;
			}
		}
//		for(auto j=a[i].s.begin();j!=a[i].s.end();j++){
//			for(auto k=a[i].s.begin();k!=a[i].s.end();k++){
//				flag[*j][*k]=true; 
//			}
//		}
	}
	for(int k=0;k<m;k++){
		for(int i=0;i<m;i++){
			if(i==k) continue;
			for(int j=0;j<m;j++){
				if(i==j||j==k) continue;
				if(mp[i][k]==2147483647||mp[j][k]==2147483647) continue;
				if(!flag[i][j]){
//					cout<<i<<" "<<j<<" "<<k<<"  "<<mp[i][k]<<" "<<mp[j][k]<<" "<<2*mp[k][k]<<"\n"; 
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[j][k]);
				}
				else{
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[j][k]-2*val[vis[i][j]][k]);
					//cout<<i+1<<" "<<j+1<<" "<<k+1<<"  "<<mp[i][k]<<" "<<mp[j][k]<<" "<<val[vis[i][j]][k]<<"\n";
				}
				mp[j][i]=mp[i][j];
			}
		}
	}
//	for(int i=0;i<m;i++){
//		for(int j=0;j<m;j++){
//			cout<<mp[i][j]+mp[i][i]+mp[j][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		int x_r,y_r;
		cin>>x_r>>y_r;
		cout<<mp[x_r-1][y_r-1]+mp[x_r-1][x_r-1]+mp[y_r-1][y_r-1]<<"\n";
	}
	
	return 0;
}
/*0  17 32 17 31
17 0  17 16 16
32 17 0  31 25
17 16 31 0  30
31 16 25 30 0*/
