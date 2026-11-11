#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
bool a[15];
int main(){
	freopen("travel.in","r",stdin);
//	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	a[1]=false;a[2]=false;a[3]=false;a[4]=true;a[6]=true;
	if (c!=cc){cout<<"0000";return 0;}
	if (s[0]!=ss[0]||s[1]!=ss[1]){cout<<"1000";return 0;}
	int x=s[2]-'A'+1,xx=ss[2]-'A'+1;
	if (a[x]!=a[xx]){cout<<"1100";return 0;}
	if (x>xx){
		int t=x;
		x=xx;xx=t;
	}
//	cout<<x<<' '<<xx<<endl;
	if (xx-x==1&&xx<=3){cout<<"1111";return 0;}
	else if (xx==6&&x==4){cout<<"1111";return 0;}
	else{cout<<"1110";return 0;}
	return 0;
}
