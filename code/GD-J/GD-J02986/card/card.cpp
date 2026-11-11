#include<bits/stdc++.h>
using namespace std;
int maxa=0,a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i]<<" ";
	}
	return 0;
	
}
