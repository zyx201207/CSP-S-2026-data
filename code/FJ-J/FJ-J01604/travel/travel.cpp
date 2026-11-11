#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,x,y;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}else cout<<'0';
	for(int i=0;i<=2;i++){
		if(i<=1){
			x+=s1[i];
			y+=s2[i];
		}
		if(i==2){
			if(x==y&&c1==c2){
				cout<<'1';
			}else cout<<'0';
		}
		if(i==2){
			if(x==y&&c1==c2&&!(s2[2]=='D'&&s1[2]=='C')&&!(s1[2]=='D'&&s2[2]=='C')){
				cout<<'1';
			}else cout<<'0';
			if(!(x==y)||!(c1==c2)||!(s1[2]=='A'&&s2[2]=='B')||!(s1[2]=='B'&&s2[2]=='C')||!(s1[2]=='D'&&s2[2]=='F')||!(s2[2]=='A'&&s1[2]=='B')||!(s2[2]=='B'&&s1[2]=='C')||!(s2[2]=='D'&&s1[2]=='F')){
				cout<<'0';
			}else cout<<'1';
		}
	}
	return 0;
} 
