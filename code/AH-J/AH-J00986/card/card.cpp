#include<bits/stdc++.h>
using namespace std;
long long a[200010],sum[200010];
map<long long,long long> k;
map<long long,bool> t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<1<<" ";
	}
	return 0;
}
