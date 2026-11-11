#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int t1,t2,x1,x2;
int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		t1=(s2[0]-'0')*10+(s2[1]-'0');
		t2=(s4[0]-'0')*10+(s4[1]-'0');
		if(t1==t2){
			x1=s2[2],x2=s4[2];
		    if(x1<='C'&&x2<='C'||x1>='D'&&x2>='D'){
		    	if((x1-x2)==1||(x2-x1)==1) cout<<1111;
		    	else cout<<1110;
			} 
		    else cout<<1100;
		}
		else cout<<1000;
		
	} 
	else cout<<"0000";	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
