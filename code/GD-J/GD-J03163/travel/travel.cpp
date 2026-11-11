#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1,s1,c2,s2;
    cin>> c1>>s1>>c2>>s2;
    if(c1==c2){
    	cout<<1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	int c=0,s=0;
	if(s1[2]>='A'&&s1[2]<='C'){
		c=1;
	}else{
		c=0;
	}
	if(s2[2]>='A'&&s2[2]<='C'){
		s=1;
	}else{
		s=0;
	}
	if(c==s&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
    	cout<<1;
	}else{
		cout<<0;
	}
	if((s1[2]-1==s2[2]||s1[2]+1==s2[2])&&c==s&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2){
    	cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}
