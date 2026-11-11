#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y;
char c,a;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	n=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	m=(s[0]-'0')*10+s[1]-'0',c=s[2];
	cin>>s;
	x=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	y=(s[0]-'0')*10+s[1]-'0',a=s[2];
	if(n==x){
		cout<<1;
		if(m==y){
			cout<<1;
			if((c!='D'&&c!='F'&&a!='D'&&a!='F')||(c=='D'&&a=='F')||(c=='F'&&a=='D')){
				cout<<1;
				if(c=='D'||c=='F'||a==(c+1)||a==(c-1)) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
