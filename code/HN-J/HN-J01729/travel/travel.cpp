#include <bits/stdc++.h>
using namespace std;

string a,b,c,d;
bool q1,q2,q3,q4;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);//¼ÇµÃÉ¾
	cin>>a>>c>>b>>d;
	q1=(a==b);
	q2=q1&&(c[0]==d[0]&&c[1]==d[1]);
	q3=q2&&(c[2]<='C'&&d[2]<='C'||c[2]>='D'&&d[2]>='D');
	int e=(c[0]-'0')*10+(c[1]-'0'),f=(d[0]-'0')*10+(d[1]-'0');
	q4=abs(e-f)==1||abs(c[2]-d[2])==1;
	cout<<q1<<q2<<q3<<q4;
	return 0;
}
