#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct o{
	char a;
	ll b;
}s[200010];
ll n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (ll i=1;i<=n;i++){
		cin>>s[i].b>>s[i].a;
	}
	for (ll i=1,j=n;j>=(n+1)/2 && i<=(n+1)/2;){
		if (s[i].a != s[j].a){
			if (s[i].b > s[j].b){
				s[i].b -= s[j].b;
				ans += s[j].b;
				--j;
			}else if (s[i].b < s[j].b){
				s[j].b -= s[i].b;
				ans += s[i].b;
				++i;
			}else{
				if (i != j)ans += s[i].b;
				++i;
				--j;
			}
		}else{
			if (s[i].b != s[j].b){
				if (s[i].b > s[j].b) --j;
				else ++i;
			}else{
				++i;
				--j;
			}
		}
	}
	cout<<ans;
	return 0;
}

