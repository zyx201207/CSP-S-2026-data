#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	char a[4];
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		a[0]='1';
	}else{
		a[0]='0';
		a[2]='0';
		a[1]='0';
		a[3]='0';
	
	}
	if(a[0]=='1'){		
	for(int i=0;i<2;i++){
if(s[i]==ss[i]){
	a[1]='1';
}	else{
	a[1]='0';
}
	}
	if(a[1]=='0'){
		a[2]='0';
	}else{
		if(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F'){
			a[2]='1';
		}else{
		if(s[2]>='A'&&s[2]<='C'&&ss[2]<='C'&&ss[2]>='A')
	    a[2]='1';
	    else a[2]='0';	
		}
		
	   
	}
	if(a[2]=='0'){
		a[3]='0';
	}else{
		if(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F'){
				if(s[2]+2==ss[2]||s[2]-2==ss[2]){
			a[3]='1';
			}else{
				a[3]='0';
			}
		}
		if(s[2]>='A'&&s[2]<='C'&&ss[2]<='C'&&ss[2]>='A'){
		if(s[2]+1==ss[2]||s[2]-1==ss[2]){
			a[3]='1';
			}else{
				a[3]='0';
			}
		
		}
	
	}	

	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
