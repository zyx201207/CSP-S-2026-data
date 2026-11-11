#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll,ll>;
const ll N = 2*1e5;
ll n;
struct Chunk{ll size;char c;}chunks[N];
ll chunksize=0;
ll findchunk(ll x){//O(n)
	for(int i=1;i<=n;i++){
		if(chunks[i].size<=x){return i;}
		x-=chunks[i].size;
	}return -1;
}
ll huiwen(){//O(n/2)
	ll side=chunksize;
	ll l=0,r=side-1;
	ll ret=0;
	while(l<=r){
		ll lchunk=findchunk(l);
		ll rchunk=findchunk(r);
		char lchunkc=chunks[lchunk].c;
		char rchunkc=chunks[rchunk].c;
		if(lchunkc!=rchunkc){ret++;}
		l++;r--;
	}return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	#ifndef LOACL_RUN
		ifstream fi("string.in");
		ofstream fo("string.out");
		#define cout fo
		#define cin fi
	#endif
	cin>>n;
	for(int i=1;i<=n;i++){//O(n)
		ll a;
		cin>>a;
		char c;
		cin>>c;
		chunks[i].size=a;
		chunks[i].c=c;
		chunksize+=a;
	}
	cout<<huiwen();//o(n^2/2)
	return 0;
}
