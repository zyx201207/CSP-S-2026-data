#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int a[100001],b[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<i*b[a[i]]<<" ";
	}
	return 0;
}
