#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int f2=1,x=0,y=0;
		cin>>c1>>s1>>c2>>s2;
		char a=s1[2],b=s2[2];
		x=s1[0]-'0',y=s2[0]-'0';
		if(x==0) x=s1[1]-'0';
		else x=x*10+s1[1]-'0';
		if(y==0) y=s2[1]-'0';
		else y=y*10+s2[1]-'0';
		if(c1!=c2){
			cout<<"0000";
			return 0;
		}
			cout<<"a:"<<"1"<<"b:";
			for(int i=0;i<=1;i++){
				if(s1[i]!=s2[i]){
					f2=0;
					cout<<"0c:0";
				}
			}
			if(f2==1){
				cout<<"1"<<"c:";
				if((a=='A' && (b=='B' || b=='C')) ||(a=='B' && (b=='A' || b=='C')) ||(a=='C' && (b=='A' || b=='B')) || (a=='D' && b=='F') || (a=='F' && b=='D')){
					cout<<"1";
				}
				else cout<<"0";
			}
			cout<<"d:";
			if(x==y){
				if((a=='A' && b=='B') || (a=='B' && (b=='C' || b=='A')) || (a=='C' && (b=='B')) || (a=='D' && b=='F') ||(a=='F' && b=='D')){
					cout<<"1";
				}
				else cout<<"0";
			}
			else{
				if(abs(x-y)==1 && s1[2]==s2[2]) cout<<1;
				else cout<<0;
			}
	return 0;
}
