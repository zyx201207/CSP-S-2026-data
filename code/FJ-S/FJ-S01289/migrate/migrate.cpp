#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m;
long long a[N];
vector<long long>b;
int fin(long long x){
	int l=1,r=n;
	while(l<r){
		int mid=l+(r-l)/2;
		if(b[mid]<x) l=mid+1;
		else r=mid;
	}
	int k=0;
	while(b[r]==x){
		k++;
		r++;
	}
	return k;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		b.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b.push_back(a[i]);
		}
		sort(b.begin(),b.end());
		if(m==2){
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=fin(a[i]+3);
			cout<<ans<<'\n';	
		}
		if(m!=2) cout<<0<<'\n';
	}
	return 0;
}