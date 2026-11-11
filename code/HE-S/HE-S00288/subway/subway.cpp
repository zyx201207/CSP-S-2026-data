#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,x,y;
int a[500005],k[500005];
struct sub{
	int plat,t;
}b[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		cin>>b[i][j].plat>>b[i][j].t;
	}
	long long minn=1e9,ti;
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			minn=min(minn,ti);
			ti=0;
			for(int j=1;j<=b[i].k[i];j++){
				if(b[i][1].plat!=x)
				break;
				else{
					if(b[i][j].plat==y){
					for(int z=1;z<=j;z++){
						ti+=b[i][z].t;
					}
				}

				}
			}
		}
	}
	return 0;
}

