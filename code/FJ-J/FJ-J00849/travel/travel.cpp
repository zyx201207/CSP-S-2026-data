#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string c1,s1,c2,s2;
string a;
int main(){
	
	freopen( "travel.in","r",stdin );
	freopen( "travel.out","w",stdout );
	
	
	cin>>c1>>s1>>c2>>s2;
	if( c1==c2 ){
		a+='1';
	}else{
		cout<<"0000";
		return 0;
	}
	bool f=true;
	for( int i=0;i<2;i++ ){
		if(s1[i]!=s2[i] ){
			f=false;
			break;
		}
	}
	if(f){
		a+='1';
	}else{
		cout<<"1000";
		return 0;
	}
	if( s1[2]<='C' && s2[2]<='C' ){
		a+='1';
	}else if( s1[2]>='D' && s2[2]>='D' ){
		a+='1';
	}else{
		cout<<"1100";
		return 0;
	}
	if( s1[2]+1==s2[2] || s2[2]+1==s1[2] ){
		a+='1';
	}else{
		cout<<"1110";
		return 0;
	}	 
	cout<<"1111";
	
	return 0;
} 
