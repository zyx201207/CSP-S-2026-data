#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ull n,m,ans,sum;
vector<ll>a;
vector<ull>s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	s.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++){
		s[i]=a[i]-a[i-1]+s[i-1];
	}
	for(int i=0;i<n-1;i++){
		sum+=s[n-1]-s[i];
	}
	ans=n;
	while(ans>1){
		if(sum<=m)break;
		sum=sum-(s[ans-1]-s[ans-2])*(ans-1);
		ans--;
	}
	cout<<ans;
	return 0;
}
