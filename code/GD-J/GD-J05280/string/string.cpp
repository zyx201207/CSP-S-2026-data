#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct stu{
	ll x;
	char s;
}a[1000005];
ll n,ans=1,f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n;i++){
		cin>>a[i].x>>a[i].s;
		if(a[i].s==a[i-1].s&&f||i-1==0){
			f=true;
		}
		else{
			false;
		}
	
	}
	if(f){
		cout<<0;
	}


	return 0;
}
