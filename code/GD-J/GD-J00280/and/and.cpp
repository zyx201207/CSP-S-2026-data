//OK
//这期神了
#include<bits/stdc++.h> 
using namespace std;
#define MAXN 200100
long long n,a[MAXN],m,sum;
bool b[MAXN][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=32;j++){
			if(a[i]&(1ll<<j))b[i][j]=1;
		}
	}
	set<int>s;
	for(int i=1;i<=n;i++)s.insert(i);
	for(int k=32;k>=0;k--){
		vector<int>v;
		for(int i:s){
			if(a[i]&(1ll<<k))v.push_back(i);
		}
		if(v.size()<m)continue;
		if(v.size()==m){
			long long ans=LLONG_MAX;
			for(int i:v)ans&=a[i];
			cout<<ans;
			return 0;
		}
		sum|=(1ll<<k);
		s.clear();
		for(int i:v)s.insert(i);
	}
	cout<<sum;
	return 0;
}
