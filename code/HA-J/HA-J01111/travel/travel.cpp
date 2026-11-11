#include<bits/stdc++.h>
using namespace std;
int a,b;
char cc,ss,c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string cc,ss,c,s;
	cin>>cc>>c>>ss>>s;
	a+=(c[0]-'0')*10;
	a+=c[1]-'0';
	b+=(s[0]-'0')*10;
	b+=s[1]-'0';
	if(cc==ss){
		cout<<"1";
		if(a==b){
			cout<<"1";
			if(c[2]<='C'&&s[2]<='C'){
				cout<<"1";
				if((a-b==1||a-b==-1)&&c[2]==s[2]){
					cout<<"1";
				}
				else if((c[2]-s[2]==1||s[2]-c[2]==1)&&a==b){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(c[2]>='D'&&s[2]>='D'){
				cout<<"1";
				if((a-b==1||a-b==-1)&&c[2]==s[2]){
					cout<<"1";
				}
				else if((c[2]-s[2]==1||s[2]-c[2]==1)&&a==b){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
