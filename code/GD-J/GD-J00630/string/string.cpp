#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st string
ll n,ans;
struct chuan{
	ll c;
	char x;
}s[200050];
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>s[i].c>>s[i].x;
	ll l=1,r=n;
	for(;l<r;){
		if(s[l].x==s[r].x){
			if(s[l].c>=s[r].c)
				s[l].c-=s[r].c,r--;
			else
				s[r].c-=s[l].c,l++;
			continue;
		}
		if(s[l].c>=s[r].c){
			ans+=s[r].c;
			s[l].c-=s[r].c,r--;
		}else{
			ans+=s[l].c;
			s[r].c-=s[l].c,l++;
		}
	}
	cout<<ans;
	return 0;
}

