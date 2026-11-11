#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],d[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int c[300001]={};
		vector<int>v;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]=v.size()+1;
				v.push_back(a[j]);
			}
			else{
				for(int k=v.size()-1;k>=c[a[j]];k--){
					c[v[k]]=0;
					v.pop_back();
				}
				c[a[j]]=v.size()+1;
				v.push_back(a[j]);
			}
		}
		for(int i=1;i<=m;i++)if(c[i]!=0)d[i]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",d[i]);
	return 0;
}
