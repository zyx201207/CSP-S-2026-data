#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],ans[maxn],c[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=c[a[i]];
		ans[a[i]]++;
		while(j<n){
			j++;
			j=c[a[j]];
			ans[a[j]]++;
		}	
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
