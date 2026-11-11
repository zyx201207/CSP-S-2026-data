#include<bits/stdc++.h>
using namespace std;
deque<long long> Crystals;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long cost=0;
	Crystals.push_back(a[0]);
	for(int i=1;i<n;i++){
		long long Plus=Crystals.size()*(a[i]-a[i-1]);
		Crystals.push_back(a[i]);
		cost=cost+Plus;
		while(!Crystals.empty() && cost>m){
			cost-=(a[i]-Crystals.front());
			Crystals.pop_front();
		}
		ans=max(ans,(long long)Crystals.size());
	}
	cout<<ans;
	return 0;
}
