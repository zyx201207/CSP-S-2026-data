#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
string d,e;
ll ans,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s+=b;	
		} 
	}
	ll l=0,r=s.size();
	ll mid=(l+r)/2;
	for(int i=0;i<mid;i++){
		d+=s[i];	
	}
	for(int i=mid+1;i<r;i++){
		e+=s[i];
	}
	ll q=mid-1,p=0;
	while(q!=-1&&p!=r+1){
		if(d[q]!=e[p]) ans++;
		q--;
		p++;
	}
	cout<<ans;
	return 0;
} 
