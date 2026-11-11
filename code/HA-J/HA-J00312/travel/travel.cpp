#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int r=s1[0]+'0';
		r=r*10+(s1[1]+'0');
		int x=s2[0]+'0';
		x=x*10+(s2[1]+'0');
		if(r==x){
			cout<<1;
			int ra=s1[2]-'A',xa=s2[2]-'A';
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				cout<<1;
				if(ra==xa+1||ra==xa-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
