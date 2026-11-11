#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string c1,s1,c2,s2;
int n,m;
char a,b;
bool s=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n=s1[0]-'0'+s1[1]-'0';
	m=s2[0]-'0'+s2[1]-'0';
	a=s1[2];
	b=s2[2];
	if(c1==c2){
		cout<<"1";
		if(n==m){
			cout<<"1";
			if((a>='A' && a<='C' && b>='A' && b<='C') || ((a=='D' || a=='F') && (b=='D' && b=='F'))){
				cout<<"1";
				a=s1[2]-'A';
				b=s2[2]-'A';
				if((a+1==b && b!=4) || (b+1==a && a!=4)){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
