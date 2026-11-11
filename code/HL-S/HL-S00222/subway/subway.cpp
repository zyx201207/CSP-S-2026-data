#include<bits/stdc++.h>
using namespace std;
int c,n;
long long m,d;
int q;
int M[9999];
int line[9999][9999][2]={};
int a1[9999][9999];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>M[i];
		a1[i][i]=M[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			line[i][line[i][0][0]+1][0]=a;
			line[i][line[i][0][0]+1][1]=t;
			line[i][0][0]++;
		}	
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=line[i][0][0];j++){
			for(int k=j;k<line[i][0][0];k++){
				if(a1[line[i][j][0]][line[i][k][0]]==0)a1[line[i][j][0]][line[i][k][0]]=a1[line[i][k][0]][line[i][j][0]]=line[i][j][1]+M[line[i][j][0]]+M[line[i][k][0]];
				else a1[line[i][j][0]][line[i][k][0]]=min(a1[line[i][j][0]][line[i][k][0]],a1[line[i][k][0]][line[i][j][0]]=line[i][j][1]+M[line[i][j][0]]+M[line[i][k][0]]);
			}
		}
	}
	
	
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				a1[i][j]=min(a1[i][j],a1[i][k]+a1[k][j]);
			}
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		cout<<a1[x][y]<<'\n';
	}
	
	
	return 0;
}

