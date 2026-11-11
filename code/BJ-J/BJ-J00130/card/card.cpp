#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int a[500005];
int b[300005];
int c[300005];
int l[300005]={0};
vector<pair<int,int>> v;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		if(l[a[i]]!=0)
			v.push_back({l[a[i]],i});
		l[a[i]]=i;
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int t=0;
		for(int j=i;j<=n;j++){
			for(;v[t].f<j&&t<(int)v.size();t++);
			b[a[j]]=1;
			if(j==v[t].f){
				j=v[t].s-1;
			}
		}
		for(int j=1;j<=m;j++)
			c[j]+=b[j];
	}
	for(int i=1;i<=m;i++)
		printf("%d ",c[i]);
	return 0;
}
