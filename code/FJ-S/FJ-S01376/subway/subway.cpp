#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int inintime[500005][20];//m为站点号，d为第几条线路，值为站台到展厅时间 
int cfxl[20];
long long minn=1000000000000000;
void dfs(long long total,int x,int y){
	long long lj=0;
	stack<int> ztotal;
	for (int i=0;i<d;i++){
		if (inintime[x][i]!=-1 && inintime[y][i]!=-1){
			cfxl[i]=1;
			if (minn>total+inintime[x][i]+inintime[y][i]){
				minn=total+inintime[x][i]+inintime[y][i];
			}
		}
	}
	for (int i=0;i<d;i++){
		if (cfxl[i]==0 && inintime[x][i]!=-1){
			for (int j=0;j<m;j++){
				if (inintime[j][i]!=-1){
					dfs(total+inintime[x][i]+inintime[j][i],j,y);
				}
			}
		}
		cfxl[i]=1;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int intime[m],plan[q][2];
	for (int i=0;i<m;i++){
		cin>>intime[i];
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<d;j++){
			inintime[i][j]=-1;
		}
	}
	for (int i=0;i<n;i++){
		int k;
		cin>>k;
		for (int j=0;j<k;j++){
			int mm;
			cin>>mm;
			cin>>inintime[mm-1][i];
		}
	}
	for (int i=0;i<q;i++){
		cin>>plan[i][0]>>plan[i][1];
		plan[i][0]-=1;
		plan[i][1]-=1;
	}
	for (int zong=0;zong<q;zong++){
		long long total=intime[plan[zong][0]]+intime[plan[zong][1]];
		dfs(total,plan[zong][0],plan[zong][1]);
		cout<<minn<<endl;
		minn=1000000000000000;
	}
	return 0;
}
