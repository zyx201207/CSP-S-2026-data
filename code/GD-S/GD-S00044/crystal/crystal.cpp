#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 550000
ifstream fin("crystal.in");
ofstream fout("crystal.ans");
#define cin fin
#define cout fout
ll dat[maxn];
priority_queue<ll,vector<ll>,greater<ll> >gw;
int main(){
	ll n,m,eng=0,ans=0;
	cin>>n>>m;
	for(ll i=0,x;i<n;i++){
		cin>>x;gw.push(x);
	}
	for(ll i=0;i<n;i++){
		dat[i]=gw.top();gw.pop();
	}
	for(ll l=0,r=0;true;){
		ans=max(ans,r-l+1);
		r++;
		if(r>=n)break;
		eng+=(r-l)*(dat[r]-dat[r-1]);
		while(l<r&&eng>m){
			eng-=(dat[r]-dat[l]);
			l++;
		}
	}
	cout<<ans;
	fin.close();
	fout.close();
	return 0;
} 
