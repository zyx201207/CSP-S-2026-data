#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int ;
string a,b,c,d; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("travel3.in","r",stdin);//调试用
//	freopen("travel.out","w",stdout);//调试用
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else if(b[0]!=d[0]||b[1]!=d[1])cout<<"1000";
	else if((b[2]>='D'&&d[2]>='D')||(b[2]<'D'&&d[2]<'D')){
		if(abs(d[2]-b[2])==1)cout<<"1111";
		else cout<<"1110";
	}
	else cout<<"1100";
	return 0;
}

