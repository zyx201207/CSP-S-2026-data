#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int a[200005];
void f(int y,int s,int k){
	if(s==0 || k>n){
		if(s==0) maxx=max(maxx,y);
		return;
	}
	for(int j=k; j<=n; j++){
		f((y&a[j]),s-1,j+1);
		f(y,s,j+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		f(a[i],m,i);
	}
	cout<<maxx;
	return 0;
}
