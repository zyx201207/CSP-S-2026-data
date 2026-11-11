#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) cout<<1;
	else cout<<0;
	
	if(c1[0]==s1[0] && c1[1]==s1[1]){
		cout<<1;
	}else cout<<0;
	
	char xr=c2[2],xx=c2[2];
	if(xr!=xx && (xr<='C' || xr<='C') || (xr>='D' || xx<='D')){
		cout<<1;
	}else cout<<0;
	
	if(xr!=xx && ((xr>='D' && xx>='D') || (xr<='C' && xx<='C'))){
		if(int(xr-xx)==-1 || int(xr-xx==1)) cout<<1;
	}
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
