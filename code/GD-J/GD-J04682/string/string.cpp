#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4E5+5;
ll a[N],sl[N],sr[N];
ll n,len,ans;
char ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>ch[i];
		sl[i] = sl[i-1]+a[i];
		len += a[i];
	}
	for(int i = 0;i <= n;i++){
		sr[i]= len-sl[i-1];
	}
	ll l = 1;
	ll r = n;
	while(l < r){
		if(sl[l] <= sr[r]){
			if(ch[l] != ch[r]){
				ll t = min(len/2,sl[l])-max(sl[l-1],sr[r+1]);
				ans += t;
			}
			l++;
		}else if(sl[l] > sr[r]){
			if(ch[l] != ch[r]){
				ll t = min(len/2,sr[r])-max(sr[r+1],sl[l-1]);
				ans += t;
			}
			r--;
		}
	}
	cout<<ans;
	return 0;
}
