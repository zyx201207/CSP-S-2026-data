#include<bits/stdc++.h>
using namespace std;
int num=0;
string s1,s2,s3,s4;
int a[101];
int Q(string s){
	int O=s.size();
	for(int i=0;i<=O;i++){
		num =(s[1]-'0');
	}
	return num;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0); 
    cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	int k1=Q(s3), k2=Q(s4);
	    if(s1==s3){
	    	a[1]=1;
	    	if(s2[0]==s4[0]&&s2[1]==s4[1]){
	    	   a[2]=1;
	    	   if(s3[2]>='A'&&s3[2]<='C'||s4[2]>='A'&&s4[2]<='C'){
	    	a[3]=1;
	        if((k1-k2)==1){
	    	    a[4]=1;
		}
		}
		if(s2[2]=='C'&&s4[2]=='D'||s4[2]=='C'&&s2[2]=='D'){
           		a[3]=0;
			}
		if(s2[2]=='C'&&s4[2]=='A'||s4[2]=='C'&&s2[2]=='A'){
           		a[4]=0;
			}
        else if(s2[2]>='D'&&s4[2]<='F'&&s2[2]>='D'&&s4[2]<='F'){
           		a[3]=1,a[4]=1;
			}
        else if(s3[2]>='A'&&s3[2]<='B'&&s4[2]>='A'&&s4[2]<='B'){
           		a[3]=1,a[4]=1;
			}	
		else if(s3[2]>='B'&&s3[2]<='C'&&s4[2]>='B'&&s4[2]<='C'){
           		a[3]=1,a[4]=1;
		}	
			   }
			
			   }
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}
