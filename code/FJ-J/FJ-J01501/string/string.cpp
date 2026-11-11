#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
struct ID{
	ll a;
	char c;
}s[212345];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld", &s[i].a);
		cin>>s[i].c;
	}
	int l=1, r=n;
	while(l<r){
		if(s[l].c==s[r].c){
			if(s[l].a<=s[r].a){
				s[r].a-=s[l].a;
				s[l].a=0;
				l++;
				if(s[r].a==0) r--;
			} else{
				s[l].a-=s[r].a;
				s[r].a=0;
				r--;
			}
		} else{
			if(s[l].a<=s[r].a){
				ans+=s[l].a;
				s[r].a-=s[l].a;
				s[l].a=0;
				l++;
				if(s[r].a==0) r--;
			} else{
				ans+=s[r].a;
				s[l].a-=s[r].a;
				s[r].a=0;
				r--;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
