#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char s,t;
	cin>>a>>b>>s>>c>>d>>t;
	if(s=='F') s='E';
	if(t=='F') t='E';
	if(a==c) cout<<1;
	else{
		cout<<"0000";	return 0;
	} 
	if(b==d) cout<<1;
	else{
		cout<<"000";return 0;
	} 
	if((s-'A'+1<=3&&t-'A'+1<=3)||(s-'A'+1>=4&&t-'A'+1>=4)) cout<<1;
	else{
		cout<<"00";return 0;
	} 
	if(((s-'A'+1<=3&&t-'A'+1<=3)||(s-'A'+1>=4&&t-'A'+1>=4))&&abs((s-'A'+1)-(t-'A'+1))==1) cout<<1;
	else cout<<0; 
	return 0;
}

