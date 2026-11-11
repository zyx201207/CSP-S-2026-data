#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
ll n,a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> s[i];
	}
	ll lp = 1,rp = n;
	ll restl = a[1],restr = a[n];
	ll ans = 0;
	while(lp <= rp){
		if(s[lp] != s[rp]){
			if(restl > restr){
				restl -= restr;
				ans+=restr;
				restr = a[--rp];
			}else if(restl == restr){
				ans+=restl;
				restl = a[++lp],restr = a[--rp];
			}else{
				restr-=restl;
				ans+=restl;
				restl = a[++lp];
			}
		}else{
			if(restl > restr){
				restl -= restr;
				restr = a[--rp];
			}else if(restl == restr){
				restl = a[++lp],restr = a[--rp];
			}else{
				restr-=restl;
				restl = a[++lp];
			}
		}
	}
	cout << ans;
	return 0;
}