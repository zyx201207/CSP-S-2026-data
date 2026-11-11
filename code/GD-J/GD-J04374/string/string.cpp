#include<bits/stdc++.h>
#define int long long

using namespace std;
int n;
int l,r;
int l1,r1;
vector<pair<int,char> > e;
int ans=0;
signed main(){
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;char c;cin>>num>>c;
		if(e.size()&&c==e.back().second)e.back().first+=num;
		else e.push_back({num,c});
	}
	l=0;r=e.size()-1;
	
	while(l<=r){
		int a1=e[l].first+l1;
		int a2=e[r].first+r1;
		if(e[l].second!=e[r].second){
			if(a1>a2)ans+=a1-a2;
			else if(a2>a1)ans+=a2-a1;
			else ans+=a1;
		}
		else {
			ans=ans+l1+r1;
		}
		l1=r1=0;
		if(a1>a2)l1=a1-a2;
		else if(a1<a2)r1=a2-a1;
		l++,r--;
	}
	cout<<ans;
	return 0;
}
