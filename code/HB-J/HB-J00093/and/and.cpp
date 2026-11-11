#include<bits/stdc++.h>
#define ll long long
#define pls pair<ll,string>
#define fi first
#define se second
using namespace std;
set<pls>a;
ll pow2[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
ll n,m,maxn,ans;
map<ll,ll>mp;
string get_2(int now){
	stack<int>st;
	while(now){
		st.push(now%2);
		now/=2;
	}
	string ret="";
	while(!st.empty()){
		ret+=st.top()+'0';
		st.pop();
	}
	return ret;
}
void init(int now,int sum,set<pls>s){
	for(int i=now;i>=0;i--){
		int t=0;
		set<pls>st;
		for(auto j:s){
			if(j.se[j.se.size()-i-1]=='1')t+=j.fi,st.insert({j.fi,j.se});
		}
		if(t>=m){
			ans+=pow2[i];	
			if(t!=sum){
				init(i-1,t,st);
				return;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll t;
		cin>>t;
		mp[t]++;
		maxn=max(maxn,t);
	}
	for(auto i:mp)a.insert({i.se,get_2(i.fi)});
	for(int i=30;i>=0;i--){
		if(maxn>pow2[i]){
			init(i,n,a);
			break;
		}
	}
	cout<<ans;
	return 0;
}
//wangze new bee!
