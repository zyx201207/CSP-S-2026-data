#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],v[100005],ans[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int k=i;
		while(k<=n){
			ans[a[k]]++;
			k=v[a[k]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
