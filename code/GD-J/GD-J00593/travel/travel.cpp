#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	string a1=c1.substr(0,1),a2=c2.substr(0,1);
	string b1=c1.substr(1,1),b2=c2.substr(1,1);
	if(a1==a2&&b1==b2){
		cout<<1;
		a1=s1.substr(0,1),a2=s2.substr(0,1);
		b1=s1.substr(1,1),b2=s2.substr(1,1);
		if(a1==a2&&b1==b2){
			cout<<1;
			a1=s1.substr(2,1);
			b1=s2.substr(2,1);
			if((a1>="D"&&a1<="F"&&b1>="D"&&b1<="F")||(a1>="A"&&a1<="C"&&b1>="A"&&b1<="C")){
				cout<<1;
				if(a1=="D"&&b1=="F"||a1=="F"&&b1=="D"){
					cout<<1;
				}else if(a1=="A"&&b1=="B"||a1=="B"&&b1=="C"||a1=="C"&&b1=="B"||a1=="B"&&b1=="A"){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
