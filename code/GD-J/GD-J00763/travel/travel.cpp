#include<bits/stdc++.h>
using namespace std;
//using ll=long long;
string c1,c2,x1,x2;
bool o=0,p,l,r,e,u;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x1>>c2>>x2;
	if(c1==c2){
		cout<<1;
		p=1;
	}
	else cout<<0;
	
	if(x1[0]==x2[0] and x1[1]==x2[1] and p){
		cout<<1;
	}
	else cout<<0;
	
	if(p and x1[0]==x2[0] and x1[1]==x2[1] and x1[2]>='A' and x1[2]<='C' and x2[2]>='A' and x2[2]<='C' or p and x1[0]==x2[0] and x1[1]==x2[1] and x1[2]>='D' and x1[2]<='F' and x2[2]>='D' and x2[2]<='F'){
		cout<<1;
		//o=1;
	}
	else cout<<0;
	
	if(x1[2]>='A' and x1[2]<='C' and x2[2]>='A' and x2[2]<='C' or x1[2]>='D' and x1[2]<='F' and x2[2]>='D' and x2[2]<='F') u=1;
	
	if(x1[0]=='1' and x2[0]=='0' and x1[1]=='0' and x2[1]=='9' and x1[2]==x2[2] or x1[2]==x2[2] and x1[0]=='0' and x2[0]=='1' and x1[1]=='9' and x2[1]=='0')l=1; 
	//cout<<' '<<x1[1]<<' ';
	if(u and x1[0]=='1' and x2[0]=='2' and x1[1]=='9' and x2[1]=='0' and x1[2]==x2[2] or u and x1[2]==x2[2] and x1[0]=='2' and x2[0]=='1' and x1[1]=='0' and x2[1]=='9')l=1;
	
	if(u and x1[2]==x2[2] and x1[0]==x2[0] and x1[1]+1==x2[1] or u and x1[2]==x2[2] and x1[0]==x2[0] and x1[1]+1==x2[1]) l=1;
	//if(x1[0]!=x2[0] or !l)  e=0;
	if(u and x1[2]+1==x2[2] and x1[0]==x2[0] and x1[1]==x2[1] or u and x1[2]-1==x2[2] and x1[0]==x2[0] and x1[1]==x2[1])l=1;
	if(l)cout<<1;
	else cout<<0;
	return 0;
}
