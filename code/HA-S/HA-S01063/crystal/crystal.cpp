#include<bits/stdc++.h>
using namespace std;
int sum,ans=0,a[100005];
int c,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w"stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>a[n];
	for(int i=1;i<=n;++i){
		for(int k=1;k<=m;++k){
			if(c+1==i||c==i){
				ans=(i+c+m)/3+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
