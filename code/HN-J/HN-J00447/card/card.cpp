#include<bits/stdc++.h>
using namespace std;
long long n,m; 
long long a[500010];
long long en[300010];
long long ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=n;i>=1;i--){
		if(en[a[i]]==0){
			en[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j=en[a[j]]+1){
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
