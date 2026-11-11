#include<bits/stdc++.h>
using namespace std;
bool flag=0;
long long a,b;
string m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>m>>b>>n;
	if(a==b)
		cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(m[0]==n[0]&&m[1]==n[1])
		cout<<1;
	else
		cout<<0;
	if(m[0]==n[0]&&m[1]==n[1]){
		if((m[2]=='A' && n[2]=='B') || (m[2]=='B' && n[2]=='A')|| (m[2]=='A'&&n[2]=='C') ||(m[2]=='C' && n[2]=='A') || 
		(m[2]=='B'&&n[2]=='C')||(m[2]=='C' && n[2]=='B')||(m[2]=='D'&&n[2]=='F')||(m[2]=='F' && n[2]=='D')){
			cout<<1;
			flag=1;
		}
		else
			cout<<0;
	}
	else
		cout<<0;
	if(flag&&abs(m[2]-n[2])==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
