#include<bits/stdc++.h>
using namespace std;
string s;
long long ls,t,mid,a,n;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>c;
		for(int j=0;j<t;j++){
			s+=c;
		}
	}
	ls=s.size();
	mid=ls/2;
	for(int i=ls-1;i>mid;i--){
		if(s[i]!=s[ls-i-1]){
			a++;
			s[i]=s[ls-i-1];
		}
	}
	cout<<a;
}
