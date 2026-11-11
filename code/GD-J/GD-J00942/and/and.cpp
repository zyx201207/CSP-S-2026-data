#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
const int N=2e5+5,mod=1e9+7;
int n,m;
int a[N];
vector<int>v;
signed main(){
	File("and");
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],v.push_back(a[i]);
	int ans=0;
	for(int w=(1<<29);w>0;w>>=1){
		vector<int>v2;
		for(auto&i:v)
			if(i>=w)i-=w,v2.push_back(i);
		if(v2.size()>=m)ans+=w,swap(v,v2);
	}
	cout<<ans;
	return 0;
}