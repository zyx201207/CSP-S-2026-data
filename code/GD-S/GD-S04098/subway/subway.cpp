#include<bits/stdc++.h>
using namespace std;

//一个非常好看的屎山 


//喜极而泣 
//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
// ----------------------------------------- //
//      *     ##########        *                 //
// -----|-----------------------|----------- //
//        |                            \   |                //
//      |||||||||||||\    |||||||||||||||||||\\                  //
//hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh

long long w[500010],k[510];
long long s[1010][1010],a[510][510],t[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		//s[i][i]=w[i];//i口--i厅 
	}
	for(int i=1;i<=n;i++){//ww
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
//			long long aa;
//			cin>>aa>>t[aa][i];
//			s[aa][i]+=t[aa][i];
//			s[i][aa]+=t[aa][i];
			cin>>a[i][j];
			cin>>t[i][j];
//			s[i][j]+=t[i][j];//i厅--j站 
//			s[j][i]+=t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				s[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
			}
//			long long aa;
//			cin>>aa>>t[aa][i];
//			s[aa][i]+=t[aa][i];
//			s[i][aa]+=t[aa][i];
//			s[i][j]+=t[i][j];//i厅--j站 
//			s[j][i]+=t[i][j];
		}
	}
	for(int i=1;i<=m;i++){//ww 
		for(int j=1;j<=i;j++){
			if(s[i][j]==0&&i!=j){
				for(int l=1;l<=m;l++){
					if(s[i][l]!=0&&s[j][l]!=0){
						if(s[i][j]==0){
							s[i][j]=s[i][l]+s[j][l];
						}
						else{
							s[i][j]=min(s[i][j],s[i][l]+s[j][l]);
						}
						s[j][i]=s[i][j];
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long sx,sy;
		cin>>sx>>sy;
		cout<<s[sx][sy]+w[sx]+w[sy]<<'\n';
	}
	return 0;
} 
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3