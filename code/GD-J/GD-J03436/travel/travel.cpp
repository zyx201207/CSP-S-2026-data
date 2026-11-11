#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct Node{
	string c,s;
}r,x;

bool aa,bb,cc,dd;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(nullptr);
	
	cin>>r.c>>r.s>>x.c>>x.s;
	
	if(r.c==x.c) aa=1;
	if(aa&&(r.s[0]+r.s[1])==(x.s[0]+x.s[1])) bb=1;
	if(bb&&('A'<=r.s[2]&&'C'>=r.s[2]&&'A'<=x.s[2]&&'C'>=x.s[2])||('D'<=r.s[2]&&'F'>=r.s[2]&&'D'<=x.s[2]&&'F'>=x.s[2])) cc=1;
	if(cc&&(r.s[2]-x.s[2]==1||x.s[2]-r.s[2]==1)) dd=1;
	
	cout<<aa<<bb<<cc<<dd;
	
	return 0;
} 
