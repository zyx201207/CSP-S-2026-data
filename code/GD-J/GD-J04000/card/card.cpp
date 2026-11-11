#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int c[300005];
struct node{
	int lastx;
}b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","l",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]++];
	}
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	return 0;
}
