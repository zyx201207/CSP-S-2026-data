#include<bits/stdc++.h>
#define st first
#define nd second
#define inf int(1e9+1)
#define INF int(1E18+1)
using namespace std;
typedef long long L;
typedef unsigned long long UL;
bitset<10>b("111000");
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int nR,nX,rR,rX;
	char cR,cX;
	bool n=0,r=0,c=0,t=0;
	cin>>nR>>rR>>cR>>nX>>rX>>cX;
	if(nR==nX){
		n=1;
	}
	if(n&&rR==rX){
		r=1;
	}
	if(r&&b[cR-65]==b[cX-65]){
		c=1;
	}
	if(c&&((cR-1)==cX||(cR+1)==cX)){
		t=1;
	}
	cout<<n<<r<<c<<t;
	return 0;
}
