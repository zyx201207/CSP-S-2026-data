#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,f[500];
struct stu{
	int u,v,t;
};
bool cmp(stu x,stu y){
	return x.u<y.u;
}
int Find(int x){
	if(x!=f[x]){
		f[x]=Find(f[x]);
	}
	return f[x];
}
void Union(int x,int y){
	f[Find(x)]=f[Find(y)];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	vector<stu> e;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		int aij[a[i]],tij[a[i]];
		for(int j=0;j<a[i];j++){
			cin>>aij[j]>>tij[j];
		}
		for(int j=0;j<a[i]-1;j++){
			for(int k=j+1;k<a[i];k++){
				e.push_back({aij[j],aij[k],tij[k]+tij[j]});
			}
			
		}
	}
	int x[q+1],y[q+1];
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		int sum=w[x[i]];
		int c=x[i];
		for(int i=1;i<n;i++){
			f[i]=i;
		}
		for(int k=0;k<e.size();k++){
			if(Find(e[k].u)!=Find(e[k].v)||c==e[k].u&&e[k].v<=y[i]){
				Union(e[k].u,e[k].v);
				sum+=e[k].t;
				c=e[k].v;
				if(c==y[i]){
					sum+=w[y[i]];
					break;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
