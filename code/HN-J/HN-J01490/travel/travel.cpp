#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else if(s1[0]!=s2[0] or s1[1]!=s2[1]){
		cout<<1<<0<<0<<0;
		return 0;
	}
	else if((s1[2]<='C' and s2[2]>='D') or (s2[2]<='C' and s1[2]>='D')){
		cout<<1<<1<<0<<0;
		return 0;
	}
	else if(s1[2]+1!=s2[2] and s1[2]-1!=s2[2]){
		cout<<1<<1<<1<<0;
		return 0;
	}
	else {
		cout<<1<<1<<1<<1;
		return 0;
	}
	return 0;
}
