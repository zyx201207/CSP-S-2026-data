#include<bits/stdc++.h>
using namespace std;

const int N=2*1e5+5;
int n,m,a[N],mx;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=a[i];
		for(int j=i+1;j<=n;j++){
			ans&=a[j];
//			cout<<ans<<'\n';
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}

