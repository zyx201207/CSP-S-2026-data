#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans[N],t[N],my_used[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d".&a[i]);
		t[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(my_used,0,n);
		for(int j=i;j<=n;j++){
			if(my_used[a[j]]!=0){
				for(int k=my_used[a[j]];k<(j-my_used[a[j]]);k++)
					ans[a[k]]--;
				ans[a[j]]++;
				my_used[a[j]]=j;
			}
			else{
				ans[a[j]]++;
				my_used[a[j]]=j;
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d",ans[a[i]]);
	return 0;
}
