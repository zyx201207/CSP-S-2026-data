#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,d,f;
	char q,w;
	cin>>n>>m>>d>>f;
	q=m[2];
	w=f[2];
	string a,b;
	a=m[0]+m[1];
	b=f[0]+f[1];
	bool p=0,o=0;
	if('a'<=w&&'c'>=w) p=1;
	if('a'<=q&&'c'>=q) o=1;
	if(n==d){
		cout<<1;
	 		if(a==b) {
				cout<<1;
				if(p&&o) cout<<1;
				else cout<<0;
			}
		else cout<<"00";
	}
	else cout<<"000";
	long long h=w-q,l=q-w;
	if(h==1||p==1) cout<<1;
	else cout<<0;
	return 0;
}
