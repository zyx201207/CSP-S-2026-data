#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f1=0,f2=0,f3=0,f4=0;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
		if(c1[1]==c2[1]&&c1[2]==c2[2]){
			f1=1;	
	}
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			f2=1;
	}
		if(s1[3]<'C'&&s2[3]<'C'||s1[3]>'D'&&s2[3]>'D'){
			f3=1;
	}
		if(s1[3]+1==s2[3]||s1[3]-1==s2[3]){
			f4=1;
	}	
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
