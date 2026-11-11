#include<bits/stdc++.h>
using namespace std;
string s;
int ax,bx,p1,p2;
char AY,BY; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>p1>>s;
	ax=(s[0]-'0')*10+s[1]-'0';
	AY=s[2];
	cin>>p2>>s;
	bx=(s[0]-'0')*10+s[1]-'0';
	BY=s[2];
	if(p1==p2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(ax==bx) cout<<1;
	else{
		cout<<"000";
		return 0;	
	}
	if(AY=='F'){
		if(BY=='D') cout<<"11";
		else{
			cout<<"00";
		}
	}else if(AY=='D'){
		if(BY=='F') cout<<"11";
		else{
			cout<<"00";
		}
	}else if(AY=='C'){
		if(BY=='B' || BY=='A'){
			cout<<1;
			if(BY=='B') cout<<1;
			else cout<<0;
		}else{
			cout<<"00";
		}
	}else if(AY=='B'){
		if(BY=='A' || BY=='C'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else{
		if(BY=='C' || BY=='B'){
			cout<<1;
			if(BY=='B') cout<<1;
			else cout<<0;
		}else{
			cout<<"00";
		}
	}
	return 0;
}
