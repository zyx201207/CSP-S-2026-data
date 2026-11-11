#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],mx=-1;
void f(int an,int i,int ans){
	if(an==m||i>n){
		if(an==m){
			mx=max(mx,ans);
		}
		return;
	}
	f(an,i+1,ans);
	f(an+1,i+1,ans&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m;i++){
		f(0,i,a[i]);
	}
	cout<<mx;
	return 0;
}

