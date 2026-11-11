#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005],n,m,ans=-1e9;
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		a[i]=s;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int h=a[i]&&a[j];
			ans=max(ans,h);
		}
	}
	cout<<ans;
	return 0;
}
