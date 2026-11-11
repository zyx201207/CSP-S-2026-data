#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	if(m==1){
		cout<<ans;
		return 0;
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}
	return 0;
} 
