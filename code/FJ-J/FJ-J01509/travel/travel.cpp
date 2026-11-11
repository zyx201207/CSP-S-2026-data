#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool m1=0,m2=0,m3=0,mm=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		m1=1;
	}
	else cout<<"0";
	
	if(m1==1){
		if(s1[0]=s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			m2=1;
		}
		else cout<<"0";
	}
	else cout<<"0";
	
	if(m2==1){
		if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		    cout<<"1";
		    m3=1;
		    mm=1;
	    }
	    else if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))){
	    	cout<<"1";
			m3=1;
		}
	    else if((s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))){
	    	cout<<"1";
			m3=1;
		}
	    else if((s1[2]=='C'&&(s2[2]=='B'||s2[2]=='A'))){
	    	cout<<"1";
			m3=1;
		}
		else cout<<"0";
	}
	else cout<<"0";
	
	if(m3==1){
		if(mm==1){
			cout<<"1";
		}
	    else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
	    	cout<<"1";
		}
	    else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
