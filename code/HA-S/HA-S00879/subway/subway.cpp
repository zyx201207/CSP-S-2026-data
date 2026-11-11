#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
using namespace std;
int c,n,m,d,q;
int t[500001][501];
ll w[2000009];
vector<int>v[500009];
ll num[509][509];
void fun(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			num[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		if(v[i].size()<=1)continue;
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				num[v[i][j]][v[i][k]]=min(num[v[i][j]][v[i][k]],(ll)t[i][v[i][j]]+(ll)t[i][v[i][k]]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j)continue;
				num[i][j]=min(num[i][j],num[i][k]+num[j][k]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int aj,tj;
			cin>>aj>>tj;
			t[aj][i]=tj;
			v[aj].push_back(i);
		}
	}
	fun();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll rans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				rans=min(rans,num[v[x][j]][v[y][k]]+t[x][v[x][j]]+t[y][v[y][k]]);
			}
		}
		cout<<rans+w[x]+w[y]<<endl;
	}
	return 0;
}

