#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i]&a[j];
				ans=max(ans,x);
//				printf("%d %d %d\n",i,j,x);
			}
		}
	}else{
		sort(a+1,a+n+1);
		ans=a[n];
	}
	printf("%d",ans);
}
