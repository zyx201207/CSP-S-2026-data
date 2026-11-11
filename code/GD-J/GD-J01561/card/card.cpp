#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+8,M=3e5+8;
long long n,m;
long long a[N],ans[M],last[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(long long i=1;i<=n;i++){
		long long index=i;
		while(index<=n){
			ans[a[index]]++;
			index=last[a[index]]+1;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
