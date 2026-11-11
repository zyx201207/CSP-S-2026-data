#include<bits/stdc++.h>
using namespace std;
int cc,n,m,d,q,w[500005],k,x,y,c[501][501],f,v[501],ah[500005][501];
vector<int>a[500001],b[501];
struct V{
	int a,b;
}ee;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[x].push_back(i);
			b[i].push_back(x);
			ah[x][i]=y;
		}
	}
	for(int i=1;i<=n;i++){
		f=i;
		for(int j=1;j<=n;j++){
			c[i][j]=1e9;
		}
		c[i][i]=0;
		v[i]=i%2;
		for(int zz=n;zz>0;zz--){
			//cout<<zz<<"{ ";
			for(int j=0;j<b[f].size();j++){
				for(int z=0;z<a[b[f][j]].size();z++){
					c[i][a[b[f][j]][z]]=min(c[i][a[b[f][j]][z]],ah[b[f][j]][f]+ah[b[f][j]][a[b[f][j]][z]]+c[i][f]);
					//cout<<f<<"//"<<i<<" "<<a[b[f][j]][z]<<" : "<<c[i][a[b[f][j]][z]]<<endl;
				}
			}
			ee.a=1e9;
			for(int z=1;z<=n;z++){
				if(v[z]!=i%2&&c[i][z]<=ee.a){
					ee.a=c[i][z];
					ee.b=z;
				}
			}
			f=ee.b;
			v[f]=i%2;
			//cout<<f<<" !!!   "<<zz<<"/ / /}";
		}
		//cout<<endl;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		d=1e9;
		for(int j=0;j<a[x].size();j++){
			for(int z=0;z<a[y].size();z++){
				d=min(d,w[x]+w[y]+ah[x][a[x][j]]+ah[y][a[y][z]]+c[a[x][j]][a[y][z]]);
			}
		}
		cout<<d<<endl;
	}
}
