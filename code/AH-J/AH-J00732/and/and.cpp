#include<bits/stdc++.h>
using namespace std;
int n,m,a,ma=INT_MIN,mx=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		ma=max(ma,a);
		mx=mx and a;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(n==m){
		cout<<mx;
		return 0;
	}
	return 0;
}
