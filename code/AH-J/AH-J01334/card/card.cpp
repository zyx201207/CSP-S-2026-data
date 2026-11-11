#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[500005],bj[300005],t[500005],cnt[300005],p[300005],ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>t[i];
	ans=1;
	while(ans<=n){
		memset(p,0,sizeof(p));
		memset(bj,0,sizeof(bj));
		for(int i=1;i<=n;i++)a[i]=t[i];
		for(int i=ans;i<=n;i++){
			if(p[a[i]]==0){p[a[i]]=1,bj[a[i]]=i;}
			else {
				for(int j=bj[a[i]]+1;j<=i-1;j++){
					if(a[j]!=0){p[a[j]]=0;bj[a[j]]=0;a[j]=0;}
				}
				a[i]=0;
			}
		}
		for(int i=ans;i<=n;i++)if(p[a[i]]==1)cnt[a[i]]++;
		ans++;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
