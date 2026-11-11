#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
long long a[N],sum[i];
bool f[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
