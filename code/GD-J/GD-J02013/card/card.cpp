#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[30010],c[30010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j){
			c[a[j]]++;
			if(b[a[j]]==j) j++;
			else j=b[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",c[i]);
	return 0;
}
