#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	ans=0;
  for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans=max(a[i]&a[j],ans);
		}
	}
	cout<<ans;
	return 0;
}
