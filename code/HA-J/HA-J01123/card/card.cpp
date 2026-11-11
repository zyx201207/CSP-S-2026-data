#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[400005],a[500005],l;
struct node{
	int num,pl;
}vis[400005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
		vis[a[i]].num++;
		for(int j=i;j<=n;j++){
			if(vis[a[i]].num>=2){
				for(int j=vis[a[i]].pl;j<i;j++){
					cnt[j]--;
				}
			}
		}
		vis[a[i]].pl=i;
	}
    for(int i=1;i<=m;i++){
    	cout<<cnt[i]<<' ';
	}
	return 0;
}
