#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unordered_set<int> st;
	int n,m,f=1,mi=INT_MAX,ma=INT_MIN;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if((a[i]-a[i-1])!=(a[i-1]-a[i-2])&&i>2) f=0;
		st.insert(a[i]);
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
	}
	sort(a.begin(),a.end());
	vector<int> d;
	int fl=INT_MIN;
	for(int i=1;i<=n;i++){
		if(fl==a[i]) continue;
		if(st.find(a[i])!=st.end()) {
			d.push_back(a[i]);
			fl=a[i];
		}
	}
	if(f){
		int ans=1;
		int d=a[n]-a[n-1];
		while(m>=0){
			m-=ans*d;
			ans++;
		}
		cout<<ans-1;
	}
	else {
		int ans=0;
		for(auto i:d){
			int temp=0,t=m;
			for(int j=n;j>=1;j--){
				if(a[j]>i) continue;
				if(m<(i-a[j])) break;
				temp++;
				m=m-i+a[j];
			}
			ans=max(ans,temp);
			m=t;
		}
		cout<<ans;
	}
	return 0;
}
