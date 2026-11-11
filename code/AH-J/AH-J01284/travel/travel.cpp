#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			char a=s1[2],b=s2[2];
			if(a>b)swap(a,b);
			if(a=='A'&&b=='B' || a=='A'&&b=='C' || a=='B'&&b=='C' || a=='D'&&b=='F'){
				cout<<1;
				if(a=='A'&&b=='B' || a=='B'&&b=='C' || a=='D'&&b=='F'){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
