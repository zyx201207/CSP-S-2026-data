#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e7 + 100;
string z,w;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>z>>s2>>w;
	cout<<(s1==s2?1:0);
	cout<<(s1==s2&&z[0]==w[0]&&z[1]==w[1]?1:0);
	if(s1==s2&&z[0]==w[0]&&z[1]==w[1]){
		if(w[2]=='A'||w[2]=='B'||w[2]=='C'){
			if(z[2]=='A'||z[2]=='B'||z[2]=='C'){
				cout<<1;
			}
			else cout<<0;
		}
		else{
			if(w[2]=='D'&&z[2]=='F'){
				cout<<1;
			}
			if(w[2]=='F'&&z[2]=='D'){
				cout<<'1';
			}
			else cout<<0;
		}
	}
	else{
		cout<<"00\n";
		return 0;
	}
	bool flag=0;
	if(z[2]==w[2]-1||z[2]==w[2]+1){
		if(z[2]!='C'&&w[2]!='D'){
			if(z[2]!='D'&&w[2]!='C')flag=1;
		}
	}
	if(w[2]=='F'&&z[2]=='D')flag=1;
	if(w[2]=='D'&&z[2]=='F')flag=1;
	cout<<(s1==s2&&z[0]==w[0]&&z[1]==w[1]&&flag?1:0);
	return 0;
}

