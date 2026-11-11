#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=2147483647;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int j=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);
	for(int i=m;i>=n-m;i--){
		ans&=a[i];
	}
	cout<<ans;
}
