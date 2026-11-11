#include<bits/stdc++.h>
using namespace std;
int n,m,a[600009],t[600009],cnt,b[600009],sum[600009];
bool A=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		memset(b,0,sizeof(b));
		cnt=0;
		for(int k=i;k<=n;k++){
		if(!t[a[k]]) b[++cnt]=a[k],t[a[k]]++;
		else{
			int tmp=lower_bound(b+1,b+cnt+1,a[k])-b;
			for(int j=tmp;j<=cnt;j++) t[b[j]]--;
			cnt=tmp-1;
			b[++cnt]=a[k],t[a[k]]++;
			}
		}
		for(int i=1;i<=m;i++)
			if(t[i]) sum[i]++;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}
