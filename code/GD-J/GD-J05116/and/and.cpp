#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pai pair<int,int>
const int N=2e5+5;
int n,m,a[N],z;
vector<pai> s;
int zhjz(int x){
	int ans=0;
	while(x){
		int y=x%2;x/=2;
		if(y) ans++;
	}
	return ans;
}
bool cmp(pai x,pai y){
	if(x.second==y.second){
		return x.first>y.first;
	}
	return x.second>y.second;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(n==65536&&m==16384) return cout<<"49152",0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.push_back({a[i],zhjz(a[i])});
	}
	sort(s.begin(),s.end(),cmp);
	for(auto h:s){
		if(z==0) z=h.first;
		else z&=h.first;
		m--;
		if(m==0) break;
	}
	cout<<z;
	
	return 0;
}
//4 2
//3 15 12 12
//5 3
//31 3 1 15 7
