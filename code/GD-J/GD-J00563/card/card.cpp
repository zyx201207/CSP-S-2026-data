#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
int n,m;
int a[N];
map<int,int> id;
int ans[N],l,sum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		id.clear();
		for(int j=i;j<=n;j++)
			if(!id[a[j]])id[a[j]]=++l,ans[l]=a[j];
			else l=min(id[a[j]],l+1),ans[l]=a[j];
		for(int j=1;j<=l;j++)sum[ans[j]]++,ans[j]=0;
		l=0;
	}
	for(int i=1;i<=m;i++)printf("%d ",sum[i]);
	return 0;
}
