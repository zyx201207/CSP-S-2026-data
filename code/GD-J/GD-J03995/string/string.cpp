#include<bits/stdc++.h>
using namespace std;
long long n,m,nw=1,nex,sm;
struct str{
	long long a;
	char c;
}c[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long e;
		char f;
		cin>>e>>f;
		nex++;
		c[nex].a=e;
		c[nex].c=f;
		
	}
	while(nw<nex){
		if(c[nw].c!=c[nex].c){
			if(c[nw].a<c[nex].a){
				sm+=c[nw].a;
				c[nex].a-=c[nw].a;
				nw++;
			}
			else{
				sm+=c[nex].a;
				c[nw].a-=c[nex].a;
				nex--;
			}
		}
	}
	cout<<sm<<'\n';
	return 0;
} 
