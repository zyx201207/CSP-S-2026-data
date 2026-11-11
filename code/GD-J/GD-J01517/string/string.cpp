#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,num,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1,a;i<=n;i++){
		char c;
		cin>>a>>c;
		num+=a;
		s+=c;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		string s2=s;
		reverse(s.begin(),s.end());
		if(s==s2){
			cout<<0;
			return 0;
		}
	}
	cout<<num/2;
	return 0;
}
