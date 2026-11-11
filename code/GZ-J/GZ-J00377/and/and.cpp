//GZ-J00377 陈阳锦
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int T=0,bans=0;
int a[N];
int main(){
	freopen("and2.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bans=max(bans,a[i]);
	}
	for(int j=2;j<=m;j++){
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(bans&a[i],ans);
		for(int i=1;i<=n;i++) if(bans&a[i]==ans) a[i]=0;
		bans=ans;
	}
	cout<<bans;
	return 0;
}
