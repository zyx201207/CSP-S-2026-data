#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	int st=0,se=0,sc=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		se=1;
		cout<<1;
	}
	else cout<<0;
	int a=s1[0]*10+s1[1],b=s2[0]*10+s2[1];
	if(se&&a==b){
		sc=1;
		cout<<1;
	}
	else cout<<0;
	int x=s1[2]-'A'+1,y=s2[2]-'A'+1;
	if(x<=3&&y<=3||x>3&&y>3){
		if(sc){
			cout<<1;
			st=1;
		}
		else cout<<0; 
	}
	else cout<<0;
	if(st&&abs(x-y)==1)cout<<1;
	else cout<<0;
	return 0;
} 
