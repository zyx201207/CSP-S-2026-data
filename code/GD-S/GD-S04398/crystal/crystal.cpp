#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>a;
ll n,m,k,L=1,r=0,l=0,s=0,c,ml=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>k;
		a.push_back(k);
	}
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++){
		c=a[i]-a[i-1];
		s+=c*L;
		r++;
		L++;
		while(s>=m){
			s-=(a[i]-a[l]);
			l++;
			L--;
		}
		ml=max(ml,L);
	}
	cout<<ml;
} 
