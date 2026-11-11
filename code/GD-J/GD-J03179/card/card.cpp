#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],ans[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		map<int,int>mp;
		for(int j=i;j<=n;j++){
			int now=a[j];
			if(mp.count(a[j])&&mp[a[j]]!=0){
				int k=mp[a[j]];
				for(int e=k;e<=j;e++){
					mp[a[e]]=0;
				}
			}
			mp[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(mp[j]!=0)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
