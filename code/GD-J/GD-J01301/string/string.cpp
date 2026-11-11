#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll n,l,r,sum;
struct node{
	ll a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	for(ll i=1;i<=n;++i){
		scanf("%lld %c",&s[i].a,&s[i].c);
	}
	l=1,r=n;
	while(1){
		
		if(l==r) break;
		
		if(s[l].c==s[r].c){
			if(s[l].a==s[r].a){
				if(l==r-1) break;
				++l;
				--r;
			}else if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				--r;
			}else{
				s[r].a-=s[l].a;
				++l;
			}
		}else{
			if(s[l].a==s[r].a){
				sum+=s[r].a;
				if(l==r-1) break;
				++l;
				--r;
				
			}else if(s[l].a>s[r].a){
				sum+=s[r].a;
				s[l].a-=s[r].a;
				--r;
			}else{
				sum+=s[l].a;
				s[r].a-=s[l].a;
				++l;
			}
		}
		
	}
	printf("%lld",sum);
	return 0;
}
