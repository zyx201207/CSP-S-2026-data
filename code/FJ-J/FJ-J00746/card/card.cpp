#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500500],lst[300300],b[300300];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x=i;
		while(x<=n){
			b[a[x]]++;
			if(lst[a[x]]!=x){
				x=lst[a[x]];
				b[a[x]]--;
			}else{
				x++;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		printf("%lld ",b[i]);
	}
	return 0;
} 
