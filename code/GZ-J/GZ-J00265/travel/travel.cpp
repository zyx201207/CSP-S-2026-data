//GZ-J00265贵阳市第三中学王上清 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c1,c2;
string s1,s2;
ll a,b,c,d;
void ji(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
		if(s1[0]==s2[0]){
		    if(s1[1]==s2[1]){
			    b=1;
			    if(s1[2]<='C'&&s2[2]<='C'){
			    	c=1;
			    	if(abs((ll)(s1[2]-s2[2]))==1){
			    		d=1;
					}
				}
				if(s1[2]>='D'&&s2[2]>='D'){
					c=1;
					if(abs((ll)(s1[2]-s2[2]))==1){
			    		d=1;
					}
				}
		    }  
		}
	}
	cout<<a<<b<<c<<d;
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		ji();
	}
	return 0;
}
