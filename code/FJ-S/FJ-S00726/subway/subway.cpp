#include<bits/stdc++.h>
using namespace std;
int t[500005],b[500005][21],bl[5000005][21],su[500005],o,u;
long long bi[505][505];
	//vector <int> o;
	//priority_queue<int> p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	int k;int x,y;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			
			cin>>x>>y;
			su[x]++;
			b[x][su[x]]=i;
			bl[x][su[x]]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				bi[i][j]=1145141919810;
			}else{
				bi[i][j]=0;
			}
		}
	}long long r;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=su[i];j++){
			for(int k=1;k<j;k++){
				r=bl[i][j]+bl[i][k];
				bi[b[i][j]][b[i][k]]=min(bi[b[i][j]][b[i][k]],r);
				bi[b[i][k]][b[i][j]]=bi[b[i][j]][b[i][k]];
			}
		}
	}//cout<<n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				bi[i][j]=min(bi[i][j],bi[i][k]+bi[k][j]);
				bi[j][i]=bi[i][j];
			}
		}
	}
	long long o;
	long long u;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<bi[i][j]<<" ";
		}cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		o=t[x]+t[y],u=1145141919810;
		for(int j=1;j<=su[x];j++){
			for(int k=1;k<=su[y];k++){
				u=min(u,bi[b[x][j]][b[y][k]]+bl[x][j]+bl[y][k]);
			}
		}
		cout<<o+u<<endl;
	}
	//for(int j=1;j<=n)
} 
/*
5 5
 1 2 4 8 9
 */
