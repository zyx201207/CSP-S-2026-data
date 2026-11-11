#include<bits/stdc++.h>
using namespace std; 
int c1,s1,c2,s2; 
char a,b;
bool flag=false;  
int main() {
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	cin>>c1>>s1>>a>>c2>>s2>>b; 
	a-='A'; 
	b-='A'; 
	if(c1==c2) cout<<"1";
	else  {
		cout<<"0000"; 
		return 0; 
	}
	
	if(s1!=s2) cout<<"00";
	else {
		if(a<=2&&b<=2) cout<<"11",flag=true; 
		else if(a>=3&&b>=3) cout<<"11",flag=true; 
		else cout<<"10"; 
	}
	if(!flag) cout<<"0"; 
	else {
		if(a==0&&b==1) cout<<"1"; 
		else if(a==1&&b==0) cout<<"1"; 
		else if(a==1&&b==2) cout<<"1"; 
		else if(a==2&&b==1) cout<<"1"; 
		else if(a==3&&b==4) cout<<"1"; 
		else if(a==4&&b==3) cout<<"1"; 
		else cout<<"0"; 
	}
	return 0;
}
