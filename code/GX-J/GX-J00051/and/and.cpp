#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int z=1;z<=n-m+1;z++){
			long long ans=0;
			for(int j=z+1;j<=m;j++){
			    ans+=a[i]&a[j];
			}
			cnt=max(cnt,ans);
		}
	}
	cout<<cnt;
	return 0;
}
