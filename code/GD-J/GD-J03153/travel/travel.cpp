#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	if(n!=m)cout<<"0000",exit(0);
	else{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<1;
				if(abs(char(s1[2]-s2[2]))==1)cout<<1;
				else
				cout<<"0",exit(0);
			}
			else if(s2[2]>'C'&&s1[2]>'C'){
				cout<<1;
				if(abs(char(s1[2]-s2[2]))==2)cout<<1;
				else
				cout<<"0",exit(0);
			}
			else
			cout<<"00",exit(0);
		}
		else
		cout<<"000",exit(0);
	}
	return 0;
}
