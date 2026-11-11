#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],q1[300005],q2[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=300005;j++)
			q1[j]=q2[j]=0;
		int l=0,ans=0,sum;
		for(int j=1;j<=n;i++)
			if(a[j]==i)
				sum=j/1;
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(q1[a[j]]==0)
					l++,q1[a[j]]=1,q2[a[j]]=j/1;
				else{
					for(int e=q2[a[j]];e<=l;e++)
						q1[a[e]]=q2[a[e]]=0;
					l==q2[a[j]];
				}
			}
			if(q1[a[sum]]!=0)
				ans++;
		}
		printf("%d ",ans);
	}
}
