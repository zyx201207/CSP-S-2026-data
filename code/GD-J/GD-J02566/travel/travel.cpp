#include<bits/stdc++.h>
using namespace std;
string s1,s2,w1,w2;
int main()
{
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	cin>>s1>>w1>>s2>>w2;
	if(s1==s2){
		cout<<1;
	}
	else cout<<0;
	if(s1==s2){
		if(w1[0]==w2[0] && w1[1]==w2[1]){
			cout<<1;
		} 
		else cout<<0;
	}
	else cout<<0;
	if(s1==s2){
		if(w1[0]==w2[0] && w1[1]==w2[1]){
			if((abs(int(w1[2]-w2[2]))==1 && !(w1[2]=='C'&&w2[2]=='D' || w1[2]=='D'&&w2[2]=='C')) || (w1[2]=='A'&&w2[2]=='C' || w1[2]=='C'&&w2[2]=='A')){
				cout<<1;
			}
			else cout<<0;
		} 
		else cout<<0;
	}
	else cout<<0;
	if(s1==s2){
		if(w1[0]==w2[0] && w1[1]==w2[1]){
			if((abs(int(w1[2]-w2[2]))==1 && !(w1[2]=='C'&&w2[2]=='D' || w1[2]=='D'&&w2[2]=='C')) || (w1[2]=='A'&&w2[2]=='C' || w1[2]=='C'&&w2[2]=='A')){
				if(abs(int(w1[2]-w2[2]))==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
