#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll n,x,y;
char a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)cout<<0;
	else{
		cin>>x>>a>>y>>b;
		if(a!=b)cout<<min(x,y);
	}
	return 0;
} 
