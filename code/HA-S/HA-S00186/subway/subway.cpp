#include<bits/stdc++.h>
using namespace std;
int w[500010];
int jie[510];
int aa[500010];
int bb[500010];
long long duan[1010][1010];
vector<int> v[1010];
vector<int> vv[1010];
int vis[1010];
struct dao{
	long long zhi;
	int wei;
	bool operator <(const dao &bbb)const{
		return zhi>bbb.zhi;
	}
};
priority_queue<dao> q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c;
	int n;
	int m;
	int d;
	int qq;
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j){
				duan[i][j]=0;
			}
			else{
				duan[i][j]=1e17;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>jie[i];
		for(int j=1;j<=jie[i];j++){
			cin>>aa[j]>>bb[j];
		}
		if(c>=7&&c<=11){
			if(jie[i]==2){
				v[aa[1]].push_back(aa[2]);
				v[aa[2]].push_back(aa[1]);
				vv[aa[1]].push_back(bb[1]+bb[2]);
				vv[aa[2]].push_back(bb[1]+bb[2]);
			}
		}
		else{
			for(int j=1;j<=jie[i];j++){
				for(int l=1;l<j;l++){
					if(bb[j]+bb[l]<duan[aa[j]][aa[l]]){
						duan[aa[j]][aa[l]]=bb[j]+bb[l];
						duan[aa[l]][aa[j]]=bb[j]+bb[l];
					}
				}
			}
		}
	}
	if(c>=7&&c<=11){
		for(int i=1;i<=m;i++){
			memset(vis,0,sizeof(vis));
			q.push({0,i});
			while(!q.empty()){
				if(!vis[q.top().wei]){
					vis[q.top().wei]=1;
					duan[i][q.top().wei]=q.top().zhi;
					long long chang=q.top().zhi;
					int www=q.top().wei;
					q.pop();
					for(int j=0;j<v[www].size();j++){
						if(!vis[v[www][j]]){
							q.push({chang+vv[www][j],v[www][j]});
						}
					}					
				}
				else{
					q.pop();
				}
			}
		}
	}
	else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				for(int l=1;l<=m;l++){
					if(duan[j][i]+duan[i][l]<duan[j][l]){
						duan[j][l]=duan[j][i]+duan[i][l];
					}
				}
			}
		}
	}
	for(int i=1;i<=qq;i++){
		int xx,yy;
		cin>>xx>>yy;
		long long shuchu=duan[xx][yy];
		shuchu+=w[xx];
		shuchu+=w[yy];
		cout<<shuchu<<'\n';
	}
	return 0;
}
