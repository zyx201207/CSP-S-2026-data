#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==m){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a,a+n,greater<int>());
	ans=a[0];
	for(int i=1;i<m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
