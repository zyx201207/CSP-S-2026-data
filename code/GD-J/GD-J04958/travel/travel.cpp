#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
	    cout<<"0000";
	    return 0;
	}
	int t1=s1[0]*10+s1[1];
	int t2=s2[0]*10+s2[1];
	char r1=s1[2],r2=s2[2];
	if(t1==t2) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(r1=='D'){
		if(r2=='F') cout<<"11";
		else cout<<"00";
	}
	else if(r1=='F'){
		if(r2=='D') cout<<"11";
		else cout<<"00";
	}
	else if(r2=='D'){
		if(r1=='F') cout<<"11";
		else cout<<"00";
	}
	else if(r2=='F'){
		if(r1=='D') cout<<"11";
		else cout<<"00";
	}
	else{
		if(r1=='B'||r2=='B')
		    cout<<"11";
		else cout<<"10";
	}
	return 0;
} 
