//GZ-J00371 代清宸 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	bool f=1;
    cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<2;i++){
		if(s1[i]!=s3[i]) f=0;
	}
	if(f==1) cout<<'1';
	if(f==0){
		f=0;
		cout<<'0';
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&f==1) cout<<'1';
	else{
		f=0;
		cout<<'0';
	}
	if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='D'&&s4[2]<='F'&&f==1){
		f=0;
		cout<<'0'<<'0'<<endl;
		return 0;
	}
	if(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='A'&&s4[2]<='C'&&f==1){
		f=0;
		cout<<'0'<<'0'<<endl;
		return 0;
	}
    else{
    	if(s2[2]=='D'||s2[2]=='F'&&f==1){
    		cout<<'1'<<'1'<<endl;
    		return 0;
		}
        else{
    	    if(f==1) cout<<'1';
    	    if(char(s2[2]+1)==s4[2]||char(s2[2]-1)==s4[2]&&f==1){
    	    	cout<<'1'<<endl;
    	    	return 0;
			}
			else{
				cout<<'0';
				return 0;
			}
	   }
	}
	if(f==0) cout<<'0'<<'0'<<endl;
	return 0;
} 
