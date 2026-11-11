#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],ans;
queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=(a[i]&b[i-1]);
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				int t=a[i]&a[j]&a[k];
				ans=max(ans,t);
			}
		}
	}
	cout<<ans;
	return 0;
}
