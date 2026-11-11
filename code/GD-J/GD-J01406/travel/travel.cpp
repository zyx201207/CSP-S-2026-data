#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=(b[0]-'0')*10+b[1]-'0',y=(d[0]-'0')*10+d[1]-'0';
	bool flag1=(b[2]<='C'),flag2=(d[2]<='C'); 
	if(a!=c)cout<<"0000";
	else if(x!=y)cout<<"1000";
	else if((flag1 && flag2)==0)cout<<"1100";
	else if(abs(b[2]-d[2])==2)cout<<"1110";
	else cout<<"1111";
	return 0;
}
