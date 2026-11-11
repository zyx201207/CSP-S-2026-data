#include<bits/stdc++.h>
using namespace std;
int a[500100],n,m,cnt[300010],res[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				for(int k=c[a[j]];k<=j;k++){
					cnt[a[k]]=0;
				}
			}
			cnt[a[j]]++;
			c[a[j]]=j;
			
		}
		for(int j=1;j<=m;j++)if(c[j]>=i)res[j]+=cnt[j];
		memset(cnt,0,n);
		
	}
	for(int i=1;i<=m;i++)cout<<res[i]<<" ";
	return 0;
}

