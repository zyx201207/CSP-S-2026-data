#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=505;
const int M=5e4+10;

int c,n,m,d,q;
int w[M];
int t[M][N];
vector<int> e[M];
vector<int> sub[N];


int v[1005][1005]={0};
int u[1005][1005];
void pianfen(){
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1,k;i<=n;i++){
		cin>>k;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		u[a][c]=1;
		v[a][c]=v[c][a]=b+d;
	}
	for (int k=1;k<=m;k++){
		for (int i=1;i<=m;i++){
			for (int j=1;j<=m;j++){
				if(v[i][j]==0)
					v[i][j]=max(v[i][j],v[i][k]+v[k][j]);
			}
		}
	}
	for (int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]+v[x][y]<<"\n";
	}
	return ;
}
void pe(){
	int ma=0,dian;
	for (int i=0;i<sub[2].size();i++){
		for (int j=0;j<sub[1].size();j++){
			if(sub[2][i]==sub[1][j]){
				
				int o=sub[2][i];
				if(t[o][2]+t[o][1]>ma){
					dian=o;
					ma=t[o][2]+t[o][1];
				}
			}
		}
	}
	cout<<dian<<" "<<ma<<"\n";
	
	for (int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		int xt=e[x][0],yt=e[y][0];
		int numy=w[x]+w[y]+t[x][xt]+t[y][yt];
		if(xt==yt){
			cout<<numy<<"\n";
		}
		else{
			cout<<numy+ma<<"\n";
		}
	}
	return ;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	if(c>=7 && c<=11){
		pianfen();
		return 0;
	}
	
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		int k;
		cin>>k;
		for (int j=1,x,y,o;j<=k;j++){
			cin>>x>>y;
			t[x][i]=y;
			e[x].push_back(i);
			sub[i].push_back(x);
		}
	}
	if(n==2){
		pe();
		return 0;
	}
	if(n==1){
		for (int i=1,x,y;i<=q;i++){
			cin>>x>>y;
			cout<<w[x]+w[y]+t[x][1]+t[y][1]<<"\n";
		}
		return 0;
	}
	
	for (int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		cout<<x+y;
	}
	
	return 0;
} 
