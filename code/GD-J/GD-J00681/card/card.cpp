#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cout<<n-i+1<<' ';
	return 0;
}
