#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,a[1000000];
	cin>>n>>m;
	long long ans=0,bns=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(ans<a[i]){
			ans=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(bns<a[i]&&a[i]!=ans){
			bns=a[i];
		}
	}
	cout<<ans&&bns;
	return 0;
}
