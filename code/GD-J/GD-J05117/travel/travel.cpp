#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define frp(i,a,b) for(int (i)=(int)(a);i<=(int)(b);i++)
string A1,A2,B1,B2;
int pd(string s){
	return s[2]-'A';
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>A1>>A2>>B1>>B2;
	if(A1==B1)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string pa="",pb="";
	pa=A2[0]+A2[1],pb=B2[0]+B2[1];
	if(pa==pb)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int infA=0,infB=0;
	if(A2[2]=='A' or A2[2]=='B' or A2[2]=='C')
		infA=1;
	else
		infA=2;
	if(B2[2]=='A' or B2[2]=='B' or B2[2]=='C')
		infB=1;
	else
		infB=2;
	if(infA==infB)
		cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	int a=pd(A2),b=pd(B2);
	if(abs(a-b)==1){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
}
