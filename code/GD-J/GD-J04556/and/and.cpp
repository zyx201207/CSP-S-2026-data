#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10001];
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int maxn=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,min(a[i],a[j]));
		}
	}
	cout<<maxn;
	return 0;
}
