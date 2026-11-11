#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool d1,d2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	cout<<(a==c);
	cout<<(b[0]==d[0]&&b[1]==d[1]&&a==c);
	d1=(b[2]<='C'),d2=(d[2]<='C');
	cout<<(d1==d2&&b[0]==d[0]&&b[1]==d[1]&&a==c);
	bool f=(a==c)&&(b[0]==d[0]&&b[1]==d[1])&&(d1==d2)&&(b[2]==d[2]+1||d[2]==b[2]+1);
	cout<<f; 
	return 0;
} 
