#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010];
int u; 
int rule(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,rule);
	if(a[1]==a[n]){
		cout<<a[1];
		return 0;
	}
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		int l=a[1];
		for(int i=2;i<=n;i++){
			l=l and a[i];
		}
		cout<<l;
		return 0;
	}
	if(m==2){
		int ans=-1;
		u=a[1];
		cout<<u;
		return 0;
	}
	return 0;
}
