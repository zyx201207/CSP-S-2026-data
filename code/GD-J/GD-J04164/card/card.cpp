#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int x,y,n,m,a[500005],bz[300005],xb[300005][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(xb,0,sizeof(xb));
		p.clear();
		for(int j=i;j<=n;j++){
			if(xb[a[j]][0]==0){
				xb[a[j]][0]=1;
				xb[a[j]][1]=j;
			}
			else{
				x=xb[a[j]][1]-1;
				y=j-1;
				for(int z=x;z<y;z++)
				p[z]=0;
				xb[a[j]][1]=j;
			}
			p.push_back(a[j]);
		}
		for(auto q:p)
			bz[q]++;
	}
	for(int i=1;i<=m;i++)
	cout<<bz[i]<<" ";
	return 0;
}
