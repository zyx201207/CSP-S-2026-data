#include<bits/stdc++.h>
using namespace std;
int a[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		map<int,int>mm;
		for(int j=i;j<=n;j++){
			if(mm[a[j]]==0)mm[a[j]]=j;
			else{
				for(int l=mm[a[j]]+1;l<j;l++)
					mm[a[l]]=0;
				mm[a[j]]=j;
			}
		}
		for(int i=1;i<=m;i++)if(mm[i])ans[i]++;	
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
