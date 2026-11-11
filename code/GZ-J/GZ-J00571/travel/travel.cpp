//GZ-J00571 贵阳实验二中 刘子墨
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int e=(('A'<=b[2] && b[2]<='C')? 0:1),f=(('A'<=d[2] && d[2]<='C')? 0:1);
	if(b[0]==d[0] && b[1]==d[1]){
		cout<<1;
		if(e==f) cout<<1;
		else cout<<0;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(e==f && (abs(b[2]-d[2])==1)) cout<<1;
	else cout<<0;
	return 0;
}
