#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(char c1,char c2){
	if(c1=='A'){
		if(c2=='B')return 1;
		if(c2=='C')return 2;
		return 3;
	}
	if(c1=='B'){
		if(c2=='A'||c2=='C')return 1;
		return 3;
	}
	if(c1=='C'){
		if(c2=='B')return 1;
		if(c2=='A')return 2;
		return 3;
	}
	if(c1=='D'){
		if(c2=='F')return 1;
		return 3;
	}
	if(c2=='D')return 1;
	return 3;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	int r1=0,s1=0,r2=0,s2=0;
	char c1,c2;
	cin>>c;
	r1=r1*10+(c-'0');
	cin>>c;
	r1=r1*10+(c-'0');
	cin>>c;
	s1=s1*10+(c-'0');
	cin>>c;
	s1=s1*10+(c-'0');
	cin>>c1;
	
	cin>>c;
	r2=r2*10+(c-'0');
	cin>>c;
	r2=r2*10+(c-'0');
	cin>>c;
	s2=s2*10+(c-'0');
	cin>>c;
	s2=s2*10+(c-'0');
	cin>>c2;
	
	if(r1!=r2)cout<<"0000";
	else{
		cout<<1;
		if(s1!=s2)cout<<"000";
		else{
			cout<<1;
			int op=check(c1,c2);
			if(op==1)cout<<11;
			else if(op==2)cout<<10;
			else if(op==3)cout<<"00";
		}
	}
}
