#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,t;
};
long long minn=1e9;
int c,n,m,d,q;
vector<vector<node>> subway(5e5,vector<node>(5e5));
long long dx[505][505],map1[500][500];
vector<long long> w(5e5);

int xls[21];
int found_ligne(int x){
	int s;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=xls[i];j++){
			if(subway[i][j].a==x){
				s=i;
			}
		}
	}
	return s;
}
void found_subway(int now,int end,long long step){
	if(now==end) minn=min(minn,step);
	int nl;
	nl=found_ligne(now);
	for(int i=1;i<=m;i++){
		
		if(map1[now][i]==1&&dx[now][i]!=1&&found_ligne(i)!=nl){
			dx[now][i]=1;
			found_subway(i,end,step+w[i]+subway[now][i].t);
			dx[now][i]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){ 
		int k;
		cin>>k;
		map1[i][i]=0;
		for(int j=1;j<=k;j++){
			cin>>subway[i][j].a>>subway[i][j].t;
			map1[subway[i][j].a][subway[i][j-1].a]=1;
		}
	}
	for(int i=0;i<q;i++){
		int begin,end;
		cin>>begin>>end;
		minn=1e9;
		found_subway(begin,end,0);
		cout<<minn<<endl;
	}
	return 0;
}
