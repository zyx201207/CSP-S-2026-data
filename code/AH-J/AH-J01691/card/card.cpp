#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],cnt,num[300005],ans[300005],f,cntt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(num,0,sizeof(num));
		memset(p,0,sizeof(p));
		cnt=0;
		for(int j=i;j<=n;j++){
			f=0,cntt=cnt;
			for(int k=1;k<=cnt;k++){
				if(f==0&&p[k]==a[j])f=1,cntt=k-1;
				if(f==1)p[k]=0;
			}
			cnt=cntt;
			p[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++)num[p[j]]=1;
		for(int j=1;j<=m;j++)ans[j]+=num[j];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
