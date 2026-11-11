#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool x,y,z,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int a1=atoi(a.c_str()),c1=atoi(c.c_str());
	x=(a1==c1);
	string b11=b.substr(0,2),d11=d.substr(0,2);
	int b1=atoi(b11.c_str()),d1=atoi(d11.c_str());
	y=x&&(b1==d1);
	char b111=b[2],d111=d[2];
	z=y&&(b111<='C'&&d111<='C'||b111>='D'&&d111>='D');
	if(b111<d111)swap(b111,d111);
	int dif=b111-d111;
	w=z&&(dif==1&&b111!='D'&&b111!='F'||dif==2&&b111=='F');
	cout<<x<<y<<z<<w;
	return 0;
}
