#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll ai;
	string ci;
}a[200005];
ll n,sum;
int main(){
	freopen("string.in","r",stdin);
  	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i].ai>>a[i].ci;
		for(ll j=0;j<a[i].ai;j++){
			s+=a[i].ci;
		}
		sum+=a[i].ai;
	}
	ll nn=ceil(sum*1.0/2);
	string s1="",s2="";
	for(ll i=0;i<nn;i++){
		s1+=s[i];
		s2+=s[sum-1-i];
	}
	if(s1==s2){
		cout<<0;
	}else{
		ll p=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				p++;
			}
		}
		cout<<p;
	}
	return 0;
}
