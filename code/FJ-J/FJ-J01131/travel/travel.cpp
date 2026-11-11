#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
string c,cc,s,ss;
bool pds(string a,string b){
	bool f=1;
	for (int i=0;i<2;i++) if (a[i]!=b[i]){
		f=0;
		break;
	}
	return f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	bool pd1=pds(c,cc),pd2=s[0]==ss[0]&&s[1]==ss[1];
	bool pd3=(s[2]<='C'&&ss[2]<='C'||s[2]>'C'&&ss[2]>'C'),pd4=(s[2]>ss[2]?s[2]-ss[2]:ss[2]-s[2])==1;
	if (pd1) cout<<1;
	else cout<<0;
	if (pd1&&pd2) cout<<1;
	else cout<<0;
	if (pd1&&pd2&&pd3) cout<<1;
	else cout<<0;
	if (pd1&&pd2&&pd3&&pd4) cout<<1;
	else cout<<0;
	return 0;
}
/*
????????????
*/
