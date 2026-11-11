#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll,ll>;
ll n,m;
const ll N=5*1e5;
ll a[N];
bool ondesk[N];/*
void cardgame(ll x){
	for(int i=x;i<=n;i++){
		ondesk[i]=1;
		bool ondeskval[N];
	
	}
}*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	#ifndef LOACL_RUN
	ifstream fi("card.in");
	ofstream fo("card.out");
	#define cout fo
	#define cin fi
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}

	return 0;
}
