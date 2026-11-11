#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,l,x=1,y=1,c,d;
int a;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a>>b;
		while(a){
			s+=b;
			a--;
		}
	}
	c=s.size();
//	cout<<c<<" "<<s<<endl;
	for(ll i=0;i<=c/2;i++){
		if(s[i]!=s[c-i-1]){
			d++;
//			cout<<i<<" "<<c-i-1<<endl;
		}
	}
	cout<<d;


	return 0;
}
