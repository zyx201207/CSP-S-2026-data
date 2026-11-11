#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int a=(s1[0]-'0')+(s1[1]-'0');
	int b=(s2[0]-'0')+(s2[1]-'0');
	if(a==b){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int c=int(s1[2]);
	int d=int(s2[2]);
	if(c==68 && d==67){
		cout<<"00";
		return 0;
	}else{
		if(c==67 && d==68){
			cout<<"00";
			return 0;
		}
	}
	if(c<=67 && d<=67){
		cout<<"1";
	}else{
		if(c>67 && d>67){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	
	if(c+1==d || c-1==d){
		cout<<"1";
	}else{
		if(c==70 && d==68){
			cout<<"1";
		}else{
			if(d==70 && c==68){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
}
