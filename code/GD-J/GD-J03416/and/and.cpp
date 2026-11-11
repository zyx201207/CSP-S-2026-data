#include<bits/stdc++.h>
using namespace std;
int n,maxx,a[100005],m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
}

	for(int i=1;i<=n;i++){
	int ans=INT_MAX;
		for(int j=1;j<=m;j++){
			ans=ans and a[j];
			cout<<ans<<endl;
		}
		if(ans>maxx) maxx=ans;
		}
	cout<<maxx;
	return 0;
}
