#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int h,hh;
void pr(bool f){
	if(f)cout<<1;
	else cout<<0;
}
signed main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	bool flag1 = (a==c);
	pr(flag1);
	h = (b[0]-'0')*10 + (b[1]-'0');
	hh = (d[0]-'0')*10 + (d[1]-'0');
	bool flag2 = (flag1 && (h == hh));
	pr(flag2);
	bool fx = ('A'<=b[2] && b[2] <= 'C'), fx1 = ('A'<=d[2] && d[2] <= 'C');
	bool flag3 = (flag2 && (fx==fx1));
	pr(flag3);
	bool z = (abs(b[2]-d[2])==1);
	bool flag4 = (flag3 && z);
	pr(flag4); 
	cout<<endl;
	return 0;
} 
