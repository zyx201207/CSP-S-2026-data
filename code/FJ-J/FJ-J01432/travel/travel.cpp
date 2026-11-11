#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int s1p=0,s1g=0,s2p=0,s2g=0;
	for(int i = 0;i<s1.size();i++){
		if('0'<=s1[i]&&s1[i]<='9'){
			s1p = s1p*10+(s1[i]-'0');
		}else if('A'<=s1[i]&&s1[i]<='F'){
			s1g = s1[i]; 
		}
	}
	for(int i = 0;i<s2.size();i++){
		if('0'<=s2[i]&&s2[i]<='9'){
			s2p = s2p*10+(s2[i]-'0');
		}else if('A'<=s2[i]&&s2[i]<='F'){
			s2g = s2[i]; 
		}
	}
	bool c=0,h=0,g=0,x=0;
	if(c1==c2){
		c = 1;
		if(s1p==s2p){
			h = 1;
			if(('A'<=s1g && s1g<='C' && 'A'<=s2g && s2g<='C')){
				g = 1;
				if((s1g-s2g==1) || (s2g-s1g==1))x = 1;
			} 
			if((s1g=='D'||s1g=='F')&&(s2g=='D'||s2g=='F')){
				g = 1;
				x = 1;
			}
		}
	}
	cout<<c<<h<<g<<x;
	return 0;
}

