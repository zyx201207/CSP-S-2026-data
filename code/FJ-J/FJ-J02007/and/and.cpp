#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int b[1000005];
int c[200005];
int a[65][200005];
int ans,l,r,ml;
void f(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int now=b[i];
		for(int j=31;j>=0;j--){
			if((now>>j)&1){
				a[j][i]=1;
				ml=max(ml,j);
			}
		}
	}
//	for(int j=1;j<=n;j++){
//		for(int i=ml;i>=0;i--){
//			cout<<a[i][j];
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++)c[i]=1;
	for(int i=ml;i>=0;i--){
		int tot=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==1&&c[j]==1)tot++;
		}
//		cout<<i<<" : "<<tot<<"\n";
		if(tot<m)continue;
		ans+=(1ll<<i);
		for(int j=1;j<=n;j++){
			if(a[i][j]!=1)c[j]=0;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
//	freopen("and5.in","r",stdin);
//	freopen("and.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--)
	f();
	return 0;
}
/*
4 2
2 3 15 12 12

*/
