#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool pd[200005];
void dg(int k,int sum,int p)
{
	if(k==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=p;i<=n;i++)
	{
		if(!pd[a[i]])
		{
			pd[a[i]]=1;
			dg(k+1,sum&a[i],i);
			pd[a[i]]=0; 
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		pd[a[i]]=1;
		dg(1,a[i],i);
		pd[a[i]]=0;
	}
	printf("%d",ans);
	return 0;
}
