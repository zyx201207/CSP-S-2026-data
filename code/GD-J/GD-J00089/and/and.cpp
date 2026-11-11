#include <bits/stdc++.h>
using namespace std;
int A[10001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			ans=max(ans,A[i]&A[j]);
		}
	}
	cout<<ans<<endl;
} 
