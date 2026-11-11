#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;cin>>n>>m;
	if (m==1){
		for (int i=0;i<n;i++){
			int t;cin>>t;
			if (t>maxn) maxn=t;
		}
		cout<<maxn;
	}
	if (m==n){
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=a[0];
		for (int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
