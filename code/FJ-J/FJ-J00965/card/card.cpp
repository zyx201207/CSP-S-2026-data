#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[600000],b[600000];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int ans=i;
		i++;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				i=j+1;
			}
		}
		if(ans==i-1){
			b[a[ans]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
