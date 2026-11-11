#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
bool b=false;
long long w[50005],k[505],a[505][50005],x[10005],y[10005],cc[505][50005];
int minn=500005,xx,t[505][50005];
void f(int z,int yy,int xl,int tim){
	if(z==yy){
		minn=min(minn,tim+t[xl][yy]);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i][z]==1&&i!=xl){
			if(b){
				for(int j=1;j<=m;j++){
					if(a[i][j]==1&&j!=z&&cc[i][j]==0){
						cc[i][j]=1;
						tim+=t[xl][z]+t[i][z];
						f(j,yy,i,tim);
						tim-=t[xl][z]+t[i][z];
						cc[i][j]=0;
					}
				}
			}
			else{
				for(int j=m;j>=1;j--){
					if(a[i][j]==1&&j!=z&&cc[i][j]==0){
						cc[i][j]=1;
						tim+=t[xl][z]+t[i][z];
						f(j,yy,i,tim);
						tim-=t[xl][z]+t[i][z];
						cc[i][j]=0;
					}
				}
			}
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>c>>t[i][c];
			a[i][c]=1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		if(x[i]<y[i]){
			b=true;
		}
		for(int j=1;j<=n;j++){
			if(a[j][x[i]]==1){
				for(int jj=1;jj<=m;jj++){
					if(a[j][jj]==1&&jj!=x[i]){
						f(jj,y[i],j,w[x[i]]+w[y[i]]+t[j][x[i]]);
						break;
					}
				}
			}
		}
		cout<<minn<<"\n";
		minn=500005;
	}
	return 0;
}

