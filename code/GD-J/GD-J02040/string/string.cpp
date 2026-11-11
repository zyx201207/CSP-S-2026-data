#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;

const int MAXN = 300000;

ll ans;

struct sprt{
	int a;
	char c;
}s[MAXN];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> s[i].a >> s[i].c;
	}
	
	
	int l=1,r=1;
	ll li=0,ri=0,tmpc;
	while(l < n-r+1){
		tmpc = min(s[l].a-li,s[n-r+1].a-ri);
		ans += (s[l].c != s[n-r+1].c)*tmpc;
		
		li += tmpc;
		ri += tmpc;
		
		if(li == s[l].a){
			l++;
			li=0;
		}
		if(ri == s[n-r+1].a){
			r++;
			ri=0;
		}
	}
	cout<<ans;
	return 0;
}
