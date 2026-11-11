#include<bits/stdc++.h>
using namespace std;
long long n,m,maxs,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=(1<<m)-1;i<(1<<n);i++){
		long long cnt=0,t=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				cnt++;
				if(t==0) t=a[j+1];
				else t=t&a[j+1];
			}
		}
		if(cnt==m) maxs=max(maxs,t);
	}
	cout<<maxs;
	return 0;
}
