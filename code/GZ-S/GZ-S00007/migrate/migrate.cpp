//GZ-S00007 安顺市第一高级中学 徐陈乾康 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define rt return
#define ll long long
const ll MAXN=(ll)1e18+7;

int dfs(){
	//have no idea;
}

void Sol(){
	ll n,d;
	cin>>n>>d;
	ll tot=0;
	vector<ll> S(n+10);
	for(int i=0;i<n;i++){
		cin>>S[i];
	}
	for(int i=0;i<n;i++){
		while(S[i]){
			S[i]--;
			tot+=S[i]/2;
		}
	}
	cout<<tot<<'\n';
} 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--) Sol();
	rt 0;
}

//  普及+/提高- 
