#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		bool h[500010]={};
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i])
				for(int k=i;k<=j;k++)
					h[k]=0;
			h[a[j]]=1;
		}
		for(int j=1;j<=n;j++)
			if(h[j]) cnt[j]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}

