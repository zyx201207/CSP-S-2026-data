#include<bits/stdc++.h>
using namespace std;
int const N=200010;
long long ans,n,m;
struct zc{
	int a;
	int c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(long long i=1;i<=n;i++){
		char ss;
		scanf("%lld %c",&s[i].a,&ss);
		s[i].c=(ss-'a'+1);
		//cout<<s[i].a<<" "<<s[i].c<<endl;
	}
	int l=1,r=n;
	while(l<=r){
		if(s[l].c==s[r].c){
			if(s[l].a>s[r].a){
				r--;
			}
			else if(s[l].a<s[r].a){
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(s[l].a>s[r].a){
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
			}
			else if(s[l].a<s[r].a){
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
			}else{
				ans+=s[l].a;
				l++;
				r--;
			}
		}
		//cout<<l<<" "<<r<<" "<<ans<<endl;
	}
	printf("%lld",ans);
	return 0;
}
