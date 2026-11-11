#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s1,s2;
ll a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>s1>>m>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	a1=(s1[0]-'0')*10+s1[1]-'0';
	a2=(s2[0]-'0')*10+s2[1]-'0';
	b1=s1[2]-'A';
	b2=s2[2]-'A';
	if(n==m){
		if(a1==a2){
			if((0<=b1&&b1<=2&&0<=b2&&b2<=2)||(3<=b1&&b1<=4&&3<=b2&&b2<=4)){
				if(abs(b1-b2)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
