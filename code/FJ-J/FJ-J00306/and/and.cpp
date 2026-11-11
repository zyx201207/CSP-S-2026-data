#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n-m+1;i++){
		int cnt=a[i];
		for(int j=i+1;j<=n-m+2;j++){
			for(int k=j;k<=j+m-2;k++){
				cnt=(cnt&a[k]);
			}
			ans=max(ans,cnt);
			cnt=a[i];
		}
	}
	cout<<ans;
	return 0;
}
