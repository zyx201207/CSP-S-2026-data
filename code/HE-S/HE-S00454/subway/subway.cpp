#include<bits/stdc++.h>
using namespace std;
struct Node{
	int linee,to,weight;
};
int c,n,m,d,q;
int w[50010];
int a[500][50010];
int t[500][50010];
int vis[5010][5010];
int len[5010];
vector<pair<int,int> >b[5010];
int sum,num,cnt; 
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
		len[i]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			pair<int,int> p;
			p.first=i;
			p.second=j;
			b[a[i][j]].push_back(p);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		sum=0;
		num=1,cnt=1;
		for(int i=x;i<=y;i++){
			sum+=w[i];
			sum+=t[num][cnt];
		}
		cout<<sum<<endl;
	}
	return 0;
} 

