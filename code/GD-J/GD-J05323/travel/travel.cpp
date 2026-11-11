#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2,the_end="";
	cin>>c1>>s1>>c2>>s2;//c ³µÏá 
	if(c1==c2) the_end=the_end+"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		the_end=the_end+"1";
		if(s1[2]<='C'&&s2[2]<='C'){
			the_end=the_end+"1";
			if(abs(int(s1[2]-s2[2]))==1){
				the_end=the_end+"1";
			}else{
				the_end=the_end+"0";
			}
		}
		else if(s1[2]>'C'&&s2[2]>'C'){
			the_end=the_end+"1";
			the_end=the_end+"1";
		}else{
			the_end=the_end+"0";
			the_end=the_end+"0";
		}
	}else{
		the_end=the_end+"0";
		the_end=the_end+"0";
		the_end=the_end+"0";
	}
	cout<<the_end;
} 
