#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
bool f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=30;i>=0;i--){
		int z=1<<i,num=0;
		for(int i=1;i<=n;i++)if(!f[i]&&a[i]&z)num++;
		if(num>=m){
			ans+=z;
			for(int i=1;i<=n;i++)if(!(a[i]&z))f[i]=1;
		}
	}
	cout<<ans;
	return 0;
}

