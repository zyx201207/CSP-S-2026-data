#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string rc,rs,xc,xs;
ll f=0,q=0,z=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>rc>>rs>>xc>>xs;
	if (rc==xc) cout<<1;
	else{
		cout<<0;
		z=1;
	}
	if (rs.substr(0,2)==xs.substr(0,2)&&z==0) cout<<1;
	else{
		cout<<0;
		q=1;
	} 
	if (rs[2]=='A'&&z==0&&q==0){
		if (xs[2]=='B'||xs[2]=='C') cout<<1;
		else cout<<0;
		f=1;
	}
	else if (rs[2]=='B'&&f==0&&z==0&&q==0){
		if (xs[2]=='A'||xs[2]=='C') cout<<1;
		else  cout<<0;
		f=1;
	}
	else if (rs[2]=='C'&&f==0&&z==0&&q==0){
		if (xs[2]=='A'||xs[2]=='B') cout<<1;
		else  cout<<0;
		f=1;
	}
	else if (rs[2]=='D'&&f==0&&z==0&&q==0){
		if (xs[2]=='F') cout<<1;
		else  cout<<0;
		f=1;
	}
	else if (rs[2]=='F'&&f==0&&z==0&&q==0){
		if (xs[2]=='D') cout<<1;
		else  cout<<0;
		f=1;
	}
	else cout<<0;
	if (q==1&&abs(int(rs[2]-xs[2]))==1&&z==0&&q==0){
		if (rs[2]=='D'&&xs[2]=='C') cout<<0;
		else if (xs[2]=='D'&&rs[2]=='C') cout<<0;
		else cout<<1;
	}
	else cout<<0;
	return 0;
}
