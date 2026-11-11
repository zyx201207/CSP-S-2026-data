#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
bool flag=0;
struct stu{
	int a;
	int t;
}b[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)flag=1;
		for(int j=1;j<=k[i];j++){
			cin>>b[i][j].a>>b[i][j].t;
		}
		for(int j=1;j<=k[i];j++){
			for(int z=j+1;z<=k[i];z++){
				if(b[i][j].a>b[i][z].a)swap(b[i][j],b[i][z]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		if(flag){
			for(int j=1;j<=n;j++){
				for(int z=1;z<=k[i];z++){
				}
			}
		}
	}
	return 0;
}
