//华东师范大学附属贵阳学校 陈睿阳 GZ-S00286 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,qd,zd,mi;
int w[N];
int cnt[N],sj=0;
struct nb{
	int dd,sj;
}a[N];
bool v[N];
void dfs(int wz,int k){
	if (wz==zd){
		mi=min(mi,k+a[wz][]);
		return;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;i<=n;j++){
			if (cnt[i]>1 && v[i]==0){
				v[i]=1;
				if (a[i][j].dd==wz){
					dfs(a[i][j-1].dd,k+a[i][j].sj);
					dfs(a[i][j+1].dd,k+a[i][j].sj);
				}
				v[i]=0;
			}
		}
    }
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=n;i++){
		cin >> qd;
		for (int j=1;j<=qd;j++){
			cin >> a[i][j].dd >> a[i][j].sj;
			cnt[a[i][j].dd]++;
		}
	}
	for (int i=1;i<=q;i++){
		cin >> qd >> zd;
		v[qd]=1;
		dfs(qd,w[qd]+w[zd]);
		cout << mi << ' ';
		mi=0x3f;
	}
	return 0; 
}
