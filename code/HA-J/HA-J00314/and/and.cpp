#include<bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue <int> x;
int res,n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		x.push(t);
	}
	res=x.top();
	x.pop();
	for(int i=1;i<m;i++){
		res=(res&x.top());
		x.pop();
	}
	cout<<res;
	return 0;
} 
