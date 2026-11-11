#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]||c1[1]!=c2[1]&&c1[0]!=c2[0]){
		cout<<"0000";
		return 0; 
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]||s1[1]!=s2[1]&&s1[0]!=s2[0]){
		cout<<"1000";
		return 0; 
	}
	else if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='D'&&s2[2]<='F'){
		cout<<"1100";
		return 0; 
	}
	else if(s1[2]+1!=s2[2]){
		cout<<"1110";
		return 0; 
	}
	else{
		cout<<"1111";
		return 0; 
	}
	return 0;
}
