#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int w1,w2,z=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		z++;
	}
	else cout<<0;
	w1=(s1[0]-'0')*10+s1[1]-'0';
	w2=(s2[0]-'0')*10+s2[1]-'0';
	if(w1==w2 && c1==c2){
		cout<<1;
		z++;
	}else cout<<0;
	if(w1==w2 && c1==c2){
		if((s1[2]=='D' || s1[2]=='E')&&(s2[2]=='D' || s2[2]=='E')){
			cout<<1;
			z++;
		}else if((s1[2]=='A' || s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A' || s2[2]=='B'||s2[2]=='C')){
			cout<<1;
			z++;
		}
		
	}else cout<<0;
	if(z==3){
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B' )||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')){
			cout<<1;
		}
	}else cout<<0;
	return 0;
}
