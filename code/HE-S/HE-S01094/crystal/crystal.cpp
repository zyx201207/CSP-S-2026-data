#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans,d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	d=a[2]-a[1];
	for(int i=1;(i*(i-1)*d/2)<=m;i++){
		ans=i;
	}
	cout<<ans;
	return 0;
}
