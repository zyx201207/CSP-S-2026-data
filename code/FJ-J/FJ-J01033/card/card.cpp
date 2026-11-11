#include<bits/stdc++.h>
using namespace std;
int a[500100];
pair<bool,long long> vis[500100];
long long vis1[500100];
long long cnt[500100];
long long op,m;
void abab(long long k) {
	for(long long i=k; i<=op; i++) {
		vis[i].first=0;
		vis[i].second=0;
	}
	for(long long i=k; i<=op; i++) {
		if(vis[a[i]].first) {
			vis1[vis[a[i]].second]=-1;
			vis1[i]=1;
		}
		if(!vis[a[i]].first) {
			vis[a[i]].first=1;
			vis[a[i]].second=i;
		}
	}
	long long ab=0;
	for(long long i=k; i<=op; i++) {
		ab+=vis1[i];
		if(ab>=0)cnt[a[i]]++;
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>op>>m;
	for(long long i=1; i<=op; i++) {
		cin>>a[i];
	}
	for(long long i=1; i<=op; i++) {
		abab(i);
	}
	for(long long i=1; i<m; i++) {
		cout<<cnt[i]<<" ";
	}
	cout<<cnt[m]<<endl;
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
