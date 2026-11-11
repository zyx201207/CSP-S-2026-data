#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=300005;
int n,m,a[N],ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			ans[a[i]]++;
			int j=n;
			while(a[j]!=a[i])	j--;
			i=j;
		}
	}
	for(int i=1;i<=m;i++)	printf("%d ",ans[i]);
	return 0;
}
