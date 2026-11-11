#include<bits/stdc++.h>
using namespace std;
int n,m,s[500005],total[300005],hel[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			int x=s[j],k1=0;
			for(int k=1;k<=cnt;k++) if(hel[k]==x) k1=k;
			if(k1==0) hel[++cnt]=x;
			else{
				for(int k=k1;k<=cnt;k++) hel[k]=0;
				cnt=k1;
				hel[cnt]=x;
			}
		}
		for(int j=1;j<=cnt;j++) total[hel[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",total[i]);
	return 0;
} 
