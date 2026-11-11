#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[200010];
long long ans;
void ad(long long pre,int st,long long _and){
	if(st>=m){
		ans=max(ans,_and);
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(i==pre)continue;
		ad(i,st+1,_and&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ad(i,1,a[i]);	
	}
	cout<<ans;
	return 0;
}
