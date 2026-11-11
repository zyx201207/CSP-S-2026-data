#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
int n,m;
void solve1(){
	map<int,int>mp;
	for(int k=1;k<=n;k++){
		map<int,int>t;
		for(int i=k;i<=n;i++){
			int now=t[a[i]];
			if(now!=0){
				for(int j=now;j<=i;j++){
					t[a[j]]=0;
				}
			}
			t[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			mp[i]+=(t[i]!=0);
		}
	}
	for(auto &c:mp){
		cout<<c.second<<" ";
	}
}
void solve2(){
	map<int,int>mp;
	map<int,int>t;
	map<int,int>ct;
	for(int i=1;i<=n;i++){
		t[a[i]]=i;
		ct[a[i]]++;
	}
	for(int k=1;k<=n;k++){
		ct[a[k]]--;
		int l=k;
		for(int i=1;i<=m;i++){
			if(ct[i]>=2){
				l=max(l,t[i]);
			}
		}
		for(int i=l;i<=n;i++){
			mp[a[i]]++;
		}
	}
	for(auto &c:mp){
		cout<<c.second<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
