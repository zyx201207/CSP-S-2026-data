#include<bits/stdc++.h>
using namespace std;

long long n,m,h,ans;
vector<int> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h;
		a.push_back(h);
	}
	sort(a.begin(),a.end());
	for(int i=1;i<=a.size();i++){
		long long g=0;
		long long d=1;
		for(int j=i-1;j>=0;j--){
			g+=a[i]-a[j];
			if(g<=m) d++;
			else break;
		}
		ans=max(ans,d);
	}
	cout<<ans;
	return 0;
}
