#include<bits/stdc++.h>
using namespace std;
#define int long long

string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string t1="";t1+=s1[0];
		t1+=s1[1];
		string t2="";t2+=s2[0];
		t2+=s2[1];
		char a=s1[2],b=s2[2];
		if(t1==t2){
			cout<<1;
			if((a>='A' and a<='C' and b>='A' and b<='C') or 
			(a>='D' and a<='F' and b>='D' and b<='F')){
				cout<<1;
				if(abs(a-b)==1){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
