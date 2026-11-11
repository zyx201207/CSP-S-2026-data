#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n == 1) cout<<0;
	else if(n == 2){
		long long k,a,ans = 0,an,c = 0;
		cin>>k>>a;
		ans = a;n-=1;an = k;
		while(n--){
			cin>>k>>a;
			an = min(an,k);
			if(ans!=a){c = 1;}
			if(c) cout<<ans;
			else cout<<0;
		}
		
	}
	else{
		long long k,a,ans = 0,c = 0;
		cin>>k>>a;
		ans = a;n-=1;
		while(n--){
			cin>>k>>a;
			if(ans!=a){c = 1;}
			if(c) cout<<n-1;
			else cout<<0;
		}
	}
	return 0;
}
