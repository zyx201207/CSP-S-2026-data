#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==y[0]&&b[1]==y[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if((b[0]==y[0]&&b[1]==y[1])&&(y[2]=='A'||y[2]=='B'||y[2]=='C')){
		    if((b[2]=='A'&&y[2]=='C')||(b[2]=='C'&&y[2]=='A')) cout<<"10";
		    else cout<<11;
		    return 0;
		}
		else cout<<"00";
	}
	else{
		if(y[2]=='D'||y[2]=='F') cout<<11;
		else cout<<"00";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
