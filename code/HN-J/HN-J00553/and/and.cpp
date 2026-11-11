#include<bits/stdc++.h>
using namespace std;

const int maxx=2e5+5;
long long n,m;
long long a[maxx];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int ans1=a[i];
		for(int j=1;j<=m;j++){
			ans1=ans1&a[i+j];	
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}

