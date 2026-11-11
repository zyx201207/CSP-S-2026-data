#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500010],Max=0,b[500010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		b[a[i]]=i;
	for(int i=1;i<=n;i++){
		auto ans=upper_bound(a+i,a+n+1,m+a[i]);
		Max=max(b[*ans]-i,Max);
	}
	cout<<Max;
}
