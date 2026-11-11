#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a,sum;
char b;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>b;
    	for(int j=1;j<=a;j++){
    		s=s+b;
		}
	}
	ll l=1,r=s.size();
	s=' '+s;
	while(l<r){
		if(s[l]!=s[r])sum++;
		l++;
		r--;
	}
	cout<<sum;
    return 0;
}
