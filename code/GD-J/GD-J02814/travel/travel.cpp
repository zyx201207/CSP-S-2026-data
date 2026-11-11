#include<bits/stdc++.h>
using namespace std;
string c[5],s[5];
string a,b;
int main(){
    
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	a=s[1];
	b=s[2];
	if(a[0]==b[0]&&a[1]==b[1]&&c[1]==c[2]){
		cout<<"1";
	 if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'){
		cout<<"1";
		
	 }else if(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F'){
		cout<<"1";
		
	 }else{
		cout<<"0";
	 }
	}else{
		cout<<"00";
	}
	
	if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C'&&c[1]==c[2]&&a[0]==b[0]&&a[1]==b[1]){
		if(a[2]+1==b[2]||b[2]+1==a[2]){
		cout<<"1";
	    }else{
		cout<<"0";
	    }
	}else if(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
