#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long x1,x2,yy,y2;string s1,s2;
char c1,c2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>s1>>x2>>s2;
	if(x1!=x2) cout<<"0000";
	else{
		cout<<"1";
		yy=(s1[0]-'0')*10+s1[1]-'0';
		y2=(s2[0]-'0')*10+s2[1]-'0';
		c1=s1[2];c2=s2[2];
		if(yy==y2){
			cout<<"1";
			if(!((c1<='C'&&c1>='A')^(c2<='C'&&c2>='A'))){
				cout<<"1";
				if(c1<='C'){
					long long t=c1-c2;
					cout<<(abs(t)==1);
				}
				else cout<<1;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
}
