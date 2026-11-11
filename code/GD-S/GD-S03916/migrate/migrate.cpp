#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50000+10;
int c,t;
struct node{
	int id,x;
}e[N];
bool cmp(node a,node b){
	return a.x<b.x;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,cnt[N][N],yy[N][N],k=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>e[i].x;
			e[i].id=i;
		}sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			int dx=i,bh=i+1,cntt=0;
			for(int j=i+1;j<=n;j++){
				while(1==1){
				 	if(e[bh].x-e[dx].x>d){
				 		cntt++;
				 		dx=bh-1;
					}
					else{
						bh+=1;
						if(bh==j){
							if(cntt<cnt[e[i].id][e[j].id]){
								cnt[e[i].id][e[j].id]=cntt;
								yy[e[i].id][e[j].id]=1;
							}
							else if(cntt==cnt[e[i].id][e[j].id]){
								yy[e[i].id][e[j].id]++;
							}
							break;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(yy[e[i].id][e[j].id]==2){
					k++;
				}
			}
		}
		cout<<k/2<<endl;
	}
	
	return 0;
}
/*
12 2
4 2
1 2 3 4
5 2
1 2 3 4 5

11 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
