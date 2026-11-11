#include <bits/stdc++.h>
using namespace std;
long long a[500010],b[300010],ans[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==0){
			b[a[i]]=i;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			ans[a[i]]++;
			i=b[a[i]];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
