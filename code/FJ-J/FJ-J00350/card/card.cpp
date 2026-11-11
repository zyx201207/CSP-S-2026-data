#include<bits/stdc++.h>
using namespace std;
int a[500005],q2[300005],ans[300005],e[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q2[a[i]]++;
		e[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=e[i];j<=n;j++){
			ans[a[j]]+=q2[i];
			j=e[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
