#include<bits/stdc++.h>
using namespace std;
long long n,ans,a,b;
struct str{
	long long t;
	char c;
}s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		long long x;
		char y;
		scanf("%lld%c%c",&x,&y,&y);
		s[i].t=x;
		s[i].c=y;
	}
	a=1,b=n;
	while(a<b){
		if(s[a].t==0){
			a++;
		}else if(s[b].t==0){
			b--;
		}
		if(s[a].c!=s[b].c){
			if(s[a].t>s[b].t){
				ans+=s[a].t-s[b].t;
				s[a].t-=s[b].t;
				b--;
			}else{
				ans+=s[b].t-s[a].t;
				s[b].t-=s[a].t;
				a++;
			}
		}else{
			if(s[a].t>s[b].t){
				s[a].t-=s[b].t;
				b--;
			}else{
				s[b].t-=s[a].t;
				a++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
