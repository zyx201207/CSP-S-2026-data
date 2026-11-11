#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string a1,a2;
		for(ll i=0;i<=1;i++){
			a1+=s1[i];
			a2+=s2[i];
		}
		if(a1==a2){
			cout<<1;
			char b1=s1[2],b2=s2[2];
			if((b1=='A'&&b2=='B')||(b1=='A'&&b2=='C')||(b1=='B'&&b2=='C')||(b1=='D'&&b2=='F')||(b2=='A'&&b1=='B')||(b2=='A'&&b1=='C')||(b2=='B'&&b1=='C')||(b2=='D'&&b1=='F')){
				cout<<1;
				if((b1=='A'&&b2=='B')||(b1=='B'&&b2=='C')||(b1=='D'&&b2=='F')||(b2=='A'&&b1=='B')||(b2=='B'&&b1=='C')||(b2=='D'&&b1=='F')){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
