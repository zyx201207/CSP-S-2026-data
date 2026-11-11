#include<bits/stdc++.h>
using namespace std;
int n;
long long m,maxx;
long long a[500010];
void op(long long x,long long b[],int y){
	if(x==m+1){
		map<long long,long long> mp;
		long long minn=1e12,maxn=-1e12;
		for(int i=1;i<=n;i++){
			mp[b[i]]++;
			maxn=max(maxn,b[i]);
			minn=min(minn,b[i]);
		}
		for(long long i=minn;i<=maxn;i++){
			maxx=max(maxx,mp[i]);
		}
		return;
	}
	for(int i=y;i<=n;i++){
		b[i]++;
		op(x+1,b,i);
		b[i]--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	op(1,a,1);
	cout<<maxx;
	return 0;
}
