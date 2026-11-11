#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+200;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			char k1=s1[2],k2=s2[2];
			if((k1=='A'||k1=='B'||k1=='C')&&(k2=='A'||k2=='B'||k2=='C')){
				if((k1=='A'&&k2=='B')||(k1=='B'&&(k2=='A'||k2=='C'))||(k1=='C'&&k2=='B')){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else if((k1=='D'||k1=='E')&&(k2=='E'||k2=='D'))cout<<1111;
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}