#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500025],k[512],za[512][512],ta[512][512];
long long tas[512],a[512][200025],h[512][512][512],hs[512][512],t[512][200024],x,y,i,j,ttime=0,i1;
long long mmin_time=LONG_LONG_MIN;
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	c+=1;
//	while(c--){
		for(i=0;i<m;i++){
			cin>>w[i];
		}
		for(i=0;i<n;i++){
			cin>>k[i];
			for(j=0;j<k[i];j++){
				cin>>a[i][j]>>t[i][j];
				za[i][a[i][j]]=t[i][j];
				ta[a[i][j]][tas[a[i][j]]++]=i;
			}
			for(i1=0;i1<i;i1++){
				for(j=0;j<k[i1];j++){
					if(a[i][j]==a[i1][j]){
						h[i][i1][hs[i][i1]++]=a[i][j];
					}
				}
			}
		}
		for(i=0;i<q;i++){
			cin>>x>>y;
			ttime=w[x]+w[y];
			for(j=1;j<=tas[x];j++){
				if(za[ta[x][j]][y]!=0){
					ttime=w[x]+w[y];
					ttime+=t[ta[x][j]][x];
					ttime+=za[ta[x][j]][y];
					ttime+=t[ta[x][j]][y];
					mmin_time=min(mmin_time,ttime);
				}else if(hs[x][y]!=0){
					for(i1=0;i1<hs[x][y];i1++){
						ttime=w[x]+w[y];
						ttime+=t[ta[x][j]][h[x][y][i1]];
						ttime+=t[ta[y][j]][h[y][x][i1]];
						ttime+=za[ta[x][j]][x];
						ttime+=t[ta[y][j]][y];
						mmin_time=min(mmin_time,ttime);
					}
				}else{
					mmin_time=min(mmin_time,rand()%d);
				}
			}
			if(mmin_time==LONG_LONG_MIN){
				cout<<0<<"\n";
				continue;
			}
			cout<<mmin_time<<"\n";
		}
//	}
	return 0;
} 
