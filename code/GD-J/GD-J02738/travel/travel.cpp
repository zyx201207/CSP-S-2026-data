#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=0;bool flag=1;bool f2=0;
	if(c1==c2){
		f1=1;
	cout<<1;
}
	else cout<<0;
	
	if(f1){
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i])flag=0;
	}if(flag)cout<<1;
	else cout<<0;
	
}else cout<<0;
if(f1){

	if(flag){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
	cout<<1;
	f2=1;
    }
	else cout<<0;
   }else if(s1[2]=='F'||s1[2]=='D'){
   	if(s2[2]=='F'||s2[2]=='D'){
   		cout<<1;
   		f2=2;
	   }else cout<<0;
   }
}else cout<<0;
   
}else cout<<0;//ok
if(f1){
    if(flag){
    	if(f2){
    		if(s1[2]=='A'){
    			if(s2[2]=='B'){
    				cout<<1;
				}else cout<<0;
			}else if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C')cout<<1;
				else cout<<0;
			}else if(s1[2]=='C'){
				if(s2[2]=='B')cout<<1;
				else cout<<0;
			}else if(s1[2]=='F'||s1[2]=='D'){
				if(s2[2]=='F'||s2[2]=='D')cout<<1;
				else cout<<0;
			}
		}else cout<<0;
	}else cout<<0;
}else cout<<0;
//ok
	return 0;
}
