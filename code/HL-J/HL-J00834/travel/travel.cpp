#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int h1=1,h2=1,h3=1,h4=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"){
		h1=0;
	}else{
		if(c1!=c2){
			h1=0;
			h2=0;
			h3=0;
			h4=0;
			cout<<h1<<h2<<h3<<h4;
	        return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			h2=0;
			break;
		}	
	}
	if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
		h3=0;
	}
	if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')){
		h4=0;
	}
	cout<<h1<<h2<<h3<<h4;
	return 0;
}