#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int n,m,ans;
struct node{
	ll num;
	char c;
}a[N];
vector<char> g;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		m+=a[i].num;
		for(int j=1;j<=a[i].num;j++) g.push_back(a[i].c);
	}
	for(int i=0;i<m/2;i++){
		if(g[i]!=g[m-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
