#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string p1,p2;
	char zw1,zw2;
	int s1l=s1.size(),s2l=s2.size();
	for(int i=0;i<s1l-1;i++)
		p1+=s1[i];
	for(int i=0;i<s1l-1;i++)
		p2+=s2[i];
	zw1=s1[s1l-1];
	zw2=s2[s2l-1];
	if(c1==c2){
		cout<<'1';
		if(p1==p2){
			cout<<'1';
			if((zw1=='E'&&zw2=='D')||(zw1=='D'&&zw2=='E'))
				cout<<"11";
			else if((zw1<='C'&&zw1>='A')&&(zw2<='C'&&zw2>='A')){
				cout<<'1';
				if(zw1=='B'||zw2=='B') cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else
			cout<<"000";
	}
	else 
		cout<<"0000";
	return 0;
} 
