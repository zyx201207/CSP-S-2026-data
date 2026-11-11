//CSP-J succeed

#include <bits/stdc++.h>
using namespace std;
#define llong long long

auto fr=[]()->void{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	return;
};

struct gh
{
	int c,s;
}r,x;

signed main()
{
	fr();
	string a,b;  cin>>r.c>>a>>x.c>>b;
	r.s=(a[0]-'0')*10+(a[1]-'0');
	x.s=(b[0]-'0')*10+(b[1]-'0');
	
	if(r.c!=x.c){
		cout<<"0000"; return 0;
	}else{
		cout<<"1";
	}
	
	if(r.s!=x.s){
		cout<<"000"; return 0;
	}else{
		cout<<"1";
	}
	
	if(((a[2]=='A' or a[2]=='B' or a[2]=='C') and (b[2]=='A' or b[2]=='B' or b[2]=='C')) or ((a[2]=='D' or a[2]=='F') and (b[2]=='D' or b[2]=='F'))){
		cout<<"1";
	}else{
		cout<<"00"; return 0;
	}
	
	if((a[2]=='D' or a[2]=='F') and (b[2]=='D' or b[2]=='F')){
		cout<<"1";
	}else if((a[2]=='A' and b[2]=='B') or (a[2]=='B' and b[2]=='C') or (a[2]=='B' and b[2]=='A') or (a[2]=='C' and b[2]=='B')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
