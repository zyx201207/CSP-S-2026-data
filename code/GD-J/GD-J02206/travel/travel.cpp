#include<bits/stdc++.h>
using namespace std; 
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{	//同车厢 
		cout<<1;
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"000";
		else{	//同一排 
			cout<<1;
			int st1=0,st2=0;
			if(s1[2]<='C') st1=1;
			else st1=2;
			if(s2[2]<='C') st2=1;
			else st2=2;
			
			if(st1!=st2) cout<<"00";
			else{	//同一侧 
				cout<<1;
				if(abs( (int)s1[2]-(int)s2[2])!=1) cout<<0;
				else cout<<1; 
			}
		}
	}
	return 0;
}
