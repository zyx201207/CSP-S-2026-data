#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(e>f)swap(e,f);
			if(e=='A'&&f=='B')cout<<"11";
			if(e=='A'&&f=='C')cout<<"10";
			if(e=='A'&&f=='D')cout<<"00";  
			if(e=='A'&&f=='F')cout<<"00";
			if(e=='B'&&f=='C')cout<<"11";
			if(e=='B'&&f=='D')cout<<"00";
			if(e=='B'&&f=='F')cout<<"00";
			if(e=='C'&&f=='D')cout<<"00";
			if(e=='C'&&f=='F')cout<<"00";
			if(e=='D'&&f=='F')cout<<"11";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
