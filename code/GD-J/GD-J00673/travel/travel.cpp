#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if (a==c) cout<<1;
	else{
		cout<<"0000";	
		return 0;
	} 
	int x=b[1]-'0'+(b[0]-'0')*10,y=d[1]-'0'+(d[0]-'0')*10;
	char c1=b[2],c2=d[2];
	if (x==y) cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	if ((c1<='C' && c2<='C') || (c1>='D' && c2>='D')) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if (abs(int(c1-c2))==1) cout<<1;
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
