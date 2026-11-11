#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],cnt[M],mp[M];
bool flag[N];
inline void solveA(int st){
	for(int i=st;i<=n;++i)
		if(a[i]!=a[i+1])
			cnt[a[i]]=i-st+1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int i;
	for(i=1;i<=n;++i){
		cin>>a[i];
		mp[a[i]]=i;
	}
	a[n+1]=M;
	i=n;
	while(i>=1&&a[i]<=a[i+1])--i;
	int l=i+1,j;
	if(l!=n)solveA(l);
	for(i=1;i<l;++i){
		j=mp[a[i]];
		while(j!=n){
//			cerr<<a[j]<<' ';
			++cnt[a[j++]];
			j=mp[a[j]];
		}
//		cerr<<a[n]<<'\n';
		++cnt[a[n]];
	}
	for(int i=1;i<=m;++i)
		cout<<cnt[i]<<' ';
	return 0;
}
