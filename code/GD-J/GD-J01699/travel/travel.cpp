#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-48)*10+(c1[1]-48),b=(c2[0]-48)*10+(c2[1]-48);
	if(a!=b) cout<<"0000";
	else{
		int cp=(s1[0]-48)*10+(s1[1]-48),sp=(s2[0]-48)*10+(s2[1]-48);
		if(cp==sp){
			char c=s1[2],s=s2[2];
			if((c>='A'&&c<='C')&&(s>='A'&&s<='C')&&c!=s){
				if((c-s==1||c-s==-1)&&((c!='C'&&s!='D')||(c!='D'&&s!='C'))) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	} 
	return 0;
}

