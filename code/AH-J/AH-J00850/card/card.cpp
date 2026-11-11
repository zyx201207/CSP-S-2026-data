#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
int b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) b[a[i]]++;
	for(int i=1;i<=m;i++){
		ans+=b[i];
		printf("%d ",ans);
	}
	
	
	return 0;
}


