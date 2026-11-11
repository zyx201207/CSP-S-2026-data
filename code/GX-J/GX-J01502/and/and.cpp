#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n-m;i--){
		int t=m,ans=a[i],z=i;
		while(t--){
			ans=ans&a[--z];
		}
		s=max(s,ans);
	}
	cout<<s;
	return 0;
}
