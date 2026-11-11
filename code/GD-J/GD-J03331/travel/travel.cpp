#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	string y,x;
	y=b[0]+b[1],x=d[0]+d[1];
	if(y==x) cout<<1;
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if(((b[b.size()-1]=='A'||b[b.size()-1]=='B'||b[b.size()-1]=='C')&&(d[d.size()-1]=='A'||d[d.size()-1]=='B'||d[d.size()-1]=='C'))||((b[b.size()-1]=='F'||b[b.size()-1]=='D')&&(d[d.size()-1]=='F'||d[d.size()-1]=='D'))){
		cout<<1;
	}
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(char(b[b.size()-1]-1)==d[d.size()-1]||char(b[b.size()-1]+1)==d[d.size()-1]) cout<<1;
	else cout<<0; 
	return 0;
} 
