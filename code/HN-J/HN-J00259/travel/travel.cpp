#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if(('D'<=s1[2] && s1[2]<='F' && 'D'<=s2[2] && s2[2]<='F') || ('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
		
	}
	else{
		cout<<0<<0<<0<<0;
	} 
	
	return 0;
} 
