#include<bits\stdc++.h>
using namespace std;
int n,m,a[500010],v[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++){
		for(int i=n;i>=k;){
			int j=i;
			while(j>=k){
				j--;
				if(a[j]==a[i])break;
			}
			if(j<k)v[a[i]]++,i--;
			else i=j;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",v[i]);
	return 0;
}
