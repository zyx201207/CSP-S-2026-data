#include<bits/stdc++.h>
using namespace std;
string a1,b1,c1,d1;
long long ans;
bool flag,cnt;
int main(){
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>d1;
	if(a1==c1){
		cout<<"1";
		int len=b1.size();
	    int len1=d1.size();
	    if(len==len1){
		  for(int i=0;i<len-1;i++){
		     if(b1[i]==d1[i]){
			   ans++;
		       }
        	}
        	if(ans==len-1){
		      cout<<"1";
		for(int i=len-1;i<len;i++){
		if(b1[i]=='A'||b1[i]=='B'||b1[i]=='C'){
		  if(d1[i]=='A'||d1[i]=='B'||d1[i]=='C'){
		  	cnt=1;
		  }
		}else if(b1[i]=='D'||b1[i]=='E'){
			if(d1[i]=='D'||d1[i]=='E'){
				cnt=1;
			}
		}		
	}

	if(cnt==1){
		cout<<"1";
			for(int i=len-1;i<len;i++){
			if((b1[i]=='A'&&d1[i]=='B')||(b1[i]=='B'&&d1[i]=='C')||(b1[i]=='B'&&d1[i]=='A')||(b1[i]=='C'&&d1[i]=='B')){
			flag=1;
		}else if((b1[i]=='D'&&d1[i]=='E')||(b1[i]=='E'&&d1[i]=='D')){
			flag=1;
		}else {
			flag=0;
		}
		}
		if(flag==1){
		cout<<"1";
	}else {
		cout<<"0";
	}
	}else {
		cout<<"00";
	}	
	}else {
		   cout<<"000";
       	}
	
}
	}else {
		cout<<"0000";
	}
	
	return 0;
}