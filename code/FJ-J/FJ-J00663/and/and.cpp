#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],ans=INT_MAX;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int j=n;
	for(int i=i;i<=m;i++){
		ans&=a[j];
		j--;
	}
	cout<<ans;
	return 0;
}
