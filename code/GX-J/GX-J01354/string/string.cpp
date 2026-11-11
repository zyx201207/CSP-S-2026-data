#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=2*1e5+10;
ll x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	ll a;
	string y;
	string s;
	ll cnt=0;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>y;
		while(a--){
			s+=y;
			}
	}
	ll len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
