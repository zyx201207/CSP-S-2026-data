#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long c,n,m,d,q;
long long w[500005],k[5005],dis[505][505],ds[505][505],ta[500][1005],w2[3][500005];
struct node{
	int x,t;
};
struct plt{
	int p,x;
};
vector<plt>pt[500005];
vector<node>g[500005];
void worka(){
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
			ds[i][i]=dis[i][i]=0;
			for(int j=1;j<=m;j++){
				if(i==j)continue;
				ds[i][j]=dis[i][j]=2147483647;
				
			}
		}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int lst=0,lt=0;
		for(int j=1;j<=k[i];j++){
			int x;cin>>x;
			cin>>ta[i][x];
			if(lst!=0){
				g[lst].push_back({x,lt+ta[i][x]});
				g[x].push_back({lst,lt+ta[i][x]});
			}
			if(m<=500){
				dis[lst][x]=lt+ta[i][x];
				ds[lst][x]=lt+ta[i][x]+w[lst]+w[x];
				dis[x][lst]=lt+ta[i][x];
				ds[lst][x]=lt+ta[i][x]+w[lst]+w[x];
			}
			lst=x;
			lt=ta[i][x];
		}
	}
	if(m<=500){
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					ds[i][j]=min(ds[i][j],dis[i][j]+w[i]+w[j]);
	//					cout<<dis[i][j]<<' ';
				}
//				cout<<'\n';
			}	
		}
	}
	while(q--){
		int s,t;cin>>s>>t;
		if(m<=500){
			cout<<ds[s][t]<<'\n';
		}
	}
}
void work2(){
	int bel[500005];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int lst=0,lt=0;
		for(int j=1;j<=k[i];j++){
			int x,t;cin>>x>>t;
			if(lst!=0){
				g[lst].push_back({x,1});
				g[x].push_back({lst,1});
			}
			lst=x;
			bel[x]=i;
			w2[i][x]=t;
		}
	}
	int s=0,x=0;
	for(int i=1;i<=m;i++){
//		cout<<"***"<<g[i].size()<<'\n';
		if(g[i].size()>x){
//			cout<<"***";
			x=g[i].size();
			s=i;
		}
	}
//	cout<<"***"<<s<<' ';
	while(q--){
		int l,r;cin>>l>>r;
		long long ans=0;
		ans+=w[l]+w[r];
		if(s==l){
			ans+=w2[bel[r]][l]+w2[bel[r]][r];
		}else if(s==r){
//			cout<<"***";
			ans+=w2[bel[l]][l]+w2[bel[l]][r];
		}else if(bel[l]==bel[r]){
			ans+=w2[bel[l]][l]+w2[bel[l]][r];
		}else if(bel[l]!=bel[r]){
//			cout<<"***";
			ans+=w2[bel[l]][l]+w2[bel[r]][r];
			ans+=w2[bel[l]][s]+w2[bel[r]][s];
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=7&&c<=11){
		worka();
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	if(n==2){
		work2();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int lst=0,lt=0;
		for(int j=1;j<=k[i];j++){
			int x,t;cin>>x>>t;
			pt[x].push_back({i,t});
		}
	}

	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	
	
	return 0;
}


/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16


*/
