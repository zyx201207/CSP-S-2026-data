#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,b,e;
string s;
int ans,cnt;
struct node{
	int a;
	char c;
}t[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t[i].a);
		cin>>t[i].c;
		cnt+=t[i].a;
	}
	int hh=1,tt=n;
	while(hh<=tt&&b<cnt/2&&e<cnt/2){
		if(t[hh].c==t[tt].c){
			if(t[hh].a>t[tt].a){
				b+=t[tt].a,e+=t[tt].a;
				t[hh].a-=t[tt].a;
				tt--;
			}else if(t[hh].a<t[tt].a){
				b+=t[hh].a,e+=t[hh].a;
				t[tt].a-=t[hh].a;
				hh++;
			}else{
				b+=t[hh].a,e+=t[hh].a,hh++,tt--;
			}
		}else{
			if(t[hh].a>t[tt].a){
				b+=t[tt].a,e+=t[tt].a;
				t[hh].a-=t[tt].a;
				ans+=t[tt].a;
				tt--;
			}else if(t[hh].a<t[tt].a){
				b+=t[hh].a,e+=t[hh].a;
				t[tt].a-=t[hh].a;
				ans+=t[hh].a;
				hh++;
			}else{
				ans+=t[hh].a,b+=t[hh].a,e+=t[hh].a,hh++,tt--;
			}
		}
	}
	
	printf("%lld",ans);
	return 0;
}
