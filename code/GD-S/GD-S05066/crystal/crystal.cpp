#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,m,a,score=0,ans=1,ansm=0;
	vector<ll> c,d;
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	fin >> n >> m;
	for(ll i=0;i<n;i++){
		fin >> a;
		c.push_back(a);
	}
	sort(c.begin(),c.end(),less<ll>());
	for(ll i=1;i<n;i++)
		d.push_back(c[i]-c[i-1]);
	for(;score+ans*d[ans-1]<=m;ans++)
		score+=ans*d[ans-1];
	ansm=ans;
	for(ll i=1;i+ans<n;i++){
		score-=c[i+ans-2]-c[i-1];ans--;
		for(;score+ans*d[i+ans-1]<=m && i+ans+1<n;ans++)
			score+=ans*d[i+ans-1];
		ansm=max(ansm,ans);
	}
	fout << ansm;
	fin.close();
	fout.close();
	return 0;
}
