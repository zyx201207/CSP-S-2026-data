#include<bits/stdc++.h>
const int inf=0x3f3f3f3f;
int c,n,m,d,q,t[500006]={0},fl[500006][500006],h1[500005],h2[500005];
void floid(){
	for(int k=1;k<=m;k++){
		for(int j=1;j<=m;j++){
			for(int i=1;i<=m;i++){
				if(fl[i][j]>fl[i][k]+fl[k][j]){
					fl[i][j]=fl[i][k]+fl[k][j]; 
				}
			}
		}
	}
}
using namespace std;
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				fl[i][j]=inf;
			}
		}
		for(int i=1;i<=m;i++){
			fl[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			cin>>t[i];
		}
		for(int i=1;i<=n;i++){
			int b;
			cin>>b;
			for(int j=1;j<=b;j++){
				cin>>h1[i]>>h2[i];
			}
			for(int j=1;j<=b;j++){
				for(int k=1;k<=b;k++){
					fl[h1[k]][h1[j]]=min(h2[k]+h2[j],fl[h1[k]][h1[j]]);
					cout<<fl[h1[k]][h1[j]]<<' ';
					fl[h1[j]][h1[k]]=min(h2[j]+h2[k],fl[h1[k]][h1[j]]);
				}
			}
		}
		floid();
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				cout<<fl[i][j]<<' ';
			}
			cout<<endl;
		}
	while(q--){
		//int h,w;
	//	cin>>h>>w;
		//cout<<fl[h][w];
	}
	return 0;
}

