#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
ll c1,c2;
bool tc(char x,char y){
	if(x-'A'<=2&&y-'A'<=2) return 1;
	else if(x-'A'>2&&y-'A'>2) return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(tc(s1[2],s2[2])){
				cout<<1;
				if(abs((s1[2]-'A')-(s2[2]-'A'))==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
