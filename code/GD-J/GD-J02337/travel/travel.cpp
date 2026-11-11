#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		int r1=(s1[0]-'0')*10+s1[1]-'0';
		int r2=(s2[0]-'0')*10+s2[1]-'0';
		if(r1==r2){
			cout<<'1';
			int k1=0,k2=0;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')k1=1;
			else k1=0;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')k2=1;
			else k2=0;			
			if(k1==k2){
				cout<<'1';
				if(k1==0)cout<<'1';
				else {
					if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')){
						cout<<'1';
					}else cout<<"0";
				}
			}
			else cout<<"00";
		}
		else cout<<"000" ;
	}
	else cout<<"0000";
	return 0;
	
} 
