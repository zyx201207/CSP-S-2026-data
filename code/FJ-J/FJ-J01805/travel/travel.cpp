#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}
	else{
		cout<<0;
	}
	string i,j;
	i=s[0];
	i+=s[1];
	j=ss[0];
	j+=ss[1];
	if(i==j&&c==cc){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s[2]<=67&&ss[2]<=67&&i==j&&c==cc)||(68<=s[2]&&68<=ss[2]&&i==j&&c==cc)){
		cout<<1;
		if(abs(s[2]-ss[2])==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<"00";
	}
	return 0;
} 
