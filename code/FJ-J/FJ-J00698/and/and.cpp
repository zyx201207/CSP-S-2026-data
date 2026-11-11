#include<bits/stdc++.h>
using namespace std;

long long a[200005];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i] and a[j]);
		}
	}
	cout<<ans;
	
	return 0;
	
}

















