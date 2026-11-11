#include<bits/stdc++.h>
using namespace std;
int n,m,s,p,a[200001],l[200001],ans[200001],i,j,k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++,s++){
			for(k=1;k<=s;k++)
				if(l[k]==a[j]){s=k-1;p=1;break;}
			if(p==0)l[s]=a[j];
			else p=0;
		}
		for(j=1;j<=s;j++)
			ans[l[j]]++;
		s=0;
	}
	for(i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
