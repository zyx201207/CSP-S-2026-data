#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		printf("%d",ans);
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		printf("%d",ans); 
	}
}
