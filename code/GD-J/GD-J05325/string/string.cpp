#include<bits/stdc++.h>
using namespace std;
struct s{int x;char c;};
int n;
s a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}cout<<a[1].x;
	return 0;
} 

