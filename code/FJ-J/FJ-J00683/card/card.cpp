#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[500005],lst[500005],c[500005],t[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++)
			if(p[j]>=i){
				c[p[j]]++;
				c[j]--;
			}
		for(int j=i;j<=n;j++)c[j]+=c[j-1];
		for(int j=i;j<=n;j++)
			if(!c[j]&&!t[a[j]]){
				t[a[j]]=1;
				cnt[a[j]]++;
			}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
