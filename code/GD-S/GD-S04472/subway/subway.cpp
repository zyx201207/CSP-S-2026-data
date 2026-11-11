#include<bits/stdc++.h>
using namespace std;
long long INF=pow(10,8);
int main(){
	int c,n,m,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int y[m];
	int c1[m][m];
	for(int i=0;i<m;i++){
		cin>>y[i];
		for(int j=0;j<m;j++){
			c1[i][j]=INF;
		}
	}
	for(int i=0;i<n;i++){
		int k=0;
		cin>>k;
		int train[k][2];
		for (int op=0;op<k;op++){
			cout<<1122<<'\n';
			cin>>train[op][0]>>train[op][1];
			train[op][0]-=1;
		}
		for (int j=0;j<k;j++){
			for (int g=j+1;g<k;g++){
				cout<<j<<" "<<g<<" "<<train[g][0]<<" "<<train[j][0];
				if(train[j][1]+train[g][1]<c1[train[j][0]][train[g][0]]){
					c1[train[j][0]][train[g][0]]=train[j][1]+train[g][1];
					c1[train[g][0]][train[j][0]]=train[j][1]+train[g][1];
					for (int qw=0;qw<m;qw++){
						if(qw!=train[g][0]){
							if(train[j][1]+train[g][1]+c1[qw][train[j][0]]<c1[qw][train[g][0]]){
								c1[qw][train[g][0]]=train[j][1]+train[g][1]+c1[qw][train[j][0]];
								c1[train[g][0]][qw]=train[j][1]+train[g][1]+c1[qw][train[j][0]];
							}
						}
					}
					for (int qw=0;qw<m;qw++){
						if(qw!=train[j][0]){
							if(train[j][1]+train[g][1]+c1[qw][train[g][0]]<c1[qw][train[j][0]]){
								c1[qw][train[j][0]]=train[j][1]+train[g][1]+c1[qw][train[g][0]];
								c1[train[j][0]][qw]=train[j][1]+train[g][1]+c1[qw][train[g][0]];
							}
						}
					}
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		int r=0,l=0;
		cin>>r>>l;
		r-=1;
		l-=1;
		cout<<c1[r][l]+y[r]+y[l]<<'\n';
	}
}
