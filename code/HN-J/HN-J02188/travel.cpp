#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	b=max(s1[2],s2[2]);
	a=min(s1[2],s2[2]);
	if(c1==c2){
	   cout<<1;
	   if(s1[0]==s2[0] && s1[1]==s2[1]){
	   	    cout<<1;
	        if(a=='A'&&b=='B')cout<<1;
            else if(a=='B'&&b=='C')cout<<1;
            else if(a=='D'&&b=='E')cout<<1;
            else if(a=='A'&&b=='C')cout<<1;
            else cout<<"00";
            if(b-a==1 && a!='C' && b!='D')cout<<1;
            else cout<<0;
	   }
	   else cout<<"000";
	}
	else cout<<"00000";
	return 0;
}

