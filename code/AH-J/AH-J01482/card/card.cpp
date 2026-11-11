#include <bits/stdc++.h>
using namespace std;
int a[1000010],t[1000010],n,m,ans[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			if(t[a[j]]==j){
				ans[a[j]]++;
				j++;
			}
			else{
				j=t[a[j]];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
