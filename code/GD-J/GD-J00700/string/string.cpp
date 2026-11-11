#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<long long,char>> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	long long l=1,r=n,ans=0;
	while(l<r){
		long long f;
		f=min(a[l].first,a[r].first);
		if(a[l].second!=a[r].second) ans+=f;
		if(a[l].first==f) l++;
		else a[l].first-=f;
		if(a[r].first==f) r--;
		else a[r].first-=f;
	}
	cout<<ans;
	return 0;
}
