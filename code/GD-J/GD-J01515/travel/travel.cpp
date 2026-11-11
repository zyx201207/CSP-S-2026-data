#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int r,r1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d;
	int s=(a[0]-'0')*10+a[1]-'0';
	int y=(c[0]-'0')*10+c[1]-'0';
	
	int s1=(b[0]-'0')*10+b[1]-'0';
	int y1=(d[0]-'0')*10+d[1]-'0';
	
	if(b[2]=='F' || b[2]=='D')r=5;
	else r=b[2]-'A'+1;
	
	if(d[2]=='F'|| d[2]=='D') r1=5;
	else r1=d[2]-'A'+1;
	
	
	if(s==y)cout<<1;
	else cout<<0;
	
	if(s1==y1 && s==y)cout<<1;
	else cout<<0;
	
	if(s1==y1 && ((r1<4 && r<4)||(r1>4 && r>4))&& s==y){
		cout<<1;
	}else cout<<0;
	if((r-r1==0 || r-r1==1 || r-r1==-1)&& s==y && s1==y1){
		cout<<1;
	}else cout<<0;
	
	return 0;
} 
