#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int a[N],b[N][32];
ll ans=INT_MAX;
int n,m;
void solve(vector<int> p,int B){
	if(p.size()==m){
		for(int i:p){
			ans&=a[i];
		}
		return;
	}
	int cnt=0;
	for(int i:p){
		if(b[i][B])cnt++;
	}
	if(cnt<m){
		solve(p,B-1);
		return;
	}
	vector<int> v;
	for(int i:p){
		if(b[i][B]) v.push_back(i);
	}
	solve(v,B-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<int> v; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<31;j++){
			if((a[i]&(1<<j))>0)b[i][j]=1;
		}
		v.push_back(i);
	}
	solve(v,30);
	cout<<ans;
	return 0;
}

