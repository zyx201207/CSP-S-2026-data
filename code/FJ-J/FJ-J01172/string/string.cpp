#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,l=1,r;
ll la,ra,anss,m;
char lc,rc;
struct data{
	ll a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) cin>>s[i].a>>s[i].c;
	for(int i=1;i<=n;i++) m+=s[i].a;
	l=1;la=s[l].a;lc=s[l].c;
	r=n;ra=s[r].a;rc=s[r].c;
	while(l<r){
		if(la>ra){
			if(lc!=rc) anss+=ra;
			la-=ra;
			ra=0;
			rc=' ';
			
		}
		else if(la<ra){
			if(lc!=rc) anss+=la;
			ra-=la;
			la=0;
			lc=' ';
		}
		else{
			if(lc!=rc) anss+=la;
			la=0;ra=0;
			lc=' ';rc=' ';
		}
		if(lc==' '){
			l++;
			la=s[l].a;
			lc=s[l].c;
		}
		if(rc==' '){
			r--;
			ra=s[r].a;
			rc=s[r].c;
		}
	}

	cout<<anss;
	return 0;
}
