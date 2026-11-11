#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[500500],xl[500500][25][4];
int zl(int start,int end,int line){
	int tmin=999999;
	for(int i=1;xl[start][i][1]!=0;i++){
		if(xl[start][i][4]!=line){
			if(xl[start][i][1]==end){
				return xl[start][i][2]+xl[start][i][3];
			}
			tmin=min(tmin,zl(xl[start][i][1],end,xl[start][i][4])+xl[start][i][2])+xl[start][i][3];
		}
		else{
			if(xl[start][i][1]==end){
				return xl[start][i][2];
			}
			tmin=min(tmin,zl(xl[start][i][1],end,xl[start][i][4])+xl[start][i][2]);
		}
	}
	return tmin;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p; 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,s[500500],wt2;
		cin>>k;
		for(int j=1;j<=k;j++){
			int wt;
			cin>>s[j]>>wt;	
			int wyy=1;
			while(xl[s[j-1]][wyy][1]!=0)wyy++;
			xl[s[j-1]][wyy][1]=s[j];
			xl[s[j-1]][wyy][2]=wt+wt2;
			xl[s[j-1]][wyy][3]=wt2;
			xl[s[j-1]][wyy][4]=i;
			wt2=wt;
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;xl[i][j][1]!=0;j++){
			cout<<i<<"->"<<xl[i][j][4]<<"_"<<xl[i][j][1]<<" "<<xl[i][j][3]<<' '<<xl[i][j][2]<<'\n';
		}
	} */
	for(int i=1;i<=p;i++){
		int start,end;
		cin>>start>>end;
		cout<<zl(start,end,xl[start][1][4])+w[start]+w[end]<<'\n';
	}
	return 0;
}
