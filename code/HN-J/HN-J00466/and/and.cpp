#include<bits/stdc++.h>
using namespace std;
int n,m,x;
long long q[200005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	for(int i=1;i<m;i++){
		sort(q+1,q+n+1);
		ans=q[n]&q[n-1];
		q[n]=ans;
		q[n-1]=0;
		
	}
	cout<<ans;
	return 0;
}
