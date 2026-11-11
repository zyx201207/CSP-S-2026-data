//GZ-J00596,遵义市第四初级中学,杨泓钦 
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=0;

	if(c1==c2){
		cout<<1;
		f=1;
	}
	else cout<<0;
	
	bool p=0;
	bool k=0;	
	
	if(s1[0]==s2[0] and f==1){
		p=1;
	}	
	
	if(s1[1]==s2[1] and f==1){
	    k=1;
	}
	
	if(p==1 and k==1)cout<<1;
	else cout<<0;
	
	if(f==0 and p==0 and k==0){
		cout<<0<<0;
		return 0;
	}
	if(f==0 and p==1 and k==0){
		cout<<0<<0;
		return 0;
	}
	if(f==0 and p==0 and k==1){
		cout<<0<<0;
		return 0;
	}	
	if(f==1 and p==0 and k==0){
		cout<<0<<0;
		return 0;
	}
	if(f==1 and p==1 and k==0){
	     cout<<0<<0;
		return 0;
	}
	if(f==1 and p==0 and k==1){
		cout<<0<<0;
		return 0;
	}
	if(p==1 and k==1 and f==1 and s1[2]=='A' and s2[2]=='B' or s1[2]=='A' and s2[2]=='C' or s1[2]=='B' and s2[2]=='C' or s1[2]=='D' and s2[2]=='F' or s2[2]=='A' and s1[2]=='B' or s2[2]=='A' and s1[2]=='C'  or s2[2]=='B' and s1[2]=='C' or s2[2]=='D' and s1[2]=='F')cout<<1;
	else cout<<0;
	
	if(p==1 and k==1 and f==1 and s1[2]=='A' and s2[2]=='B' or s1[2]=='B' and s2[2]=='C' or s1[2]=='D' and s2[2]=='F' or s2[2]=='A' and s1[2]=='B' or s2[2]=='B' and s1[2]=='C' or s2[2]=='D' and s1[2]=='F')cout<<1;
	else cout<<0;
	
       return 0;

} 
