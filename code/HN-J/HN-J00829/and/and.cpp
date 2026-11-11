#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],maxx,m,ans;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-m+1;j++){
			ans=a[j];
			for(int k=j+1;k<j+m;k++){
				ans=ans&a[j+1];
			}
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
} 
