#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],ans[N],card[N],it;
bool pd[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int k=1;k<=n;k++)
	{
		it=0;
		memset(pd,0,sizeof(pd));
		memset(card,0,sizeof(card));
		for(int i=k;i<=n;i++)
		{
			if(pd[a[i]]){
				while(1){
					pd[card[it]]=0;
					card[it]=0;
					it--;
					if(card[it]==a[i])
						break;
				}
			}else{
				card[++it]=a[i];
				pd[a[i]]=1;
			}
		}
		for(int i=1;i<=it;i++)
			ans[card[i]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
