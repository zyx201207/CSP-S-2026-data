#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	vector<char> a;
	for(int i=0;i<n;i++){
		int t;char c;
		cin>>t>>c;
		for(int i=0;i<t;i++){
			a.push_back(c);
		}
		cnt+=t;
	}
	int ans=0;
	for(int i=0;i<cnt/2;i++){
		if(a[i]!=a[n-i]) ans++;
	}
	cout<<ans;
	return 0;
//	vector<pair<int,char>> a(n+1),l(n+1),r(n+1);
//	for(int i=1;i<=n/2;i++){
//		cin>>l[i].first>>l[i].second;
//		cnt+=l[i].first;
//	}
//	for(int i=(n+1)/2;i>=1;i--){
//		cin>>r[i].first>>r[i].second;
//		cnt+=r[i].first;
//	}
	
}
