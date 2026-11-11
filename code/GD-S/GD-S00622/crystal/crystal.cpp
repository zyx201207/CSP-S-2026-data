#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000000],cnts=1,cntz=0,zzh=0,l=1,mx=1,ti=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			cnts++;
			ti++;
			cout<<i<<" "<<a[i]<<"   "<<cnts<<" "<<cntz<<" "<<zzh<<" "<<l<<"\n";
			mx=max(mx,cnts);
			continue;
		}
		zzh+=ti*cntz;
		ti=0;
		cnts++;
		cntz+=(a[i]-a[i-1]);
		zzh+=cntz;
		cout<<i<<" "<<a[i]<<"   "<<cnts<<" "<<cntz<<" "<<zzh<<" "<<l<<"\n";
		while(zzh>m){
			cout<<"!";
			if(a[l+1]==a[l]){
				l++;
				cnts--;
				continue;
			}
			cnts--;
			zzh-=cnts*(a[l+1]-a[l]);
			cntz-=(a[l+1]-a[l]);
			l++;
		}
		cout<<i<<" "<<a[i]<<"   "<<cnts<<" "<<cntz<<" "<<zzh<<" "<<l<<"\n";
		mx=max(cnts,mx);
	}
	cout<<mx;
}
