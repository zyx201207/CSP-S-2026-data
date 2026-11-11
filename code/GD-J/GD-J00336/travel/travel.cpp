#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,x;
	int rc,xc;
	cin >> rc >> r >> xc >> x;
	char rr=r[2],cr=x[2]; //ÁÐ 
	string rp = ""+r[0]+r[1],cp=""+x[0]+x[1];//ÐÐ 
	cout << (rc==xc?1:0) << (rc==xc&&rp==cp?1:0);
	bool t0 = rc==xc&&rp==cp;
	bool t = (rr < 'D' && cr < 'D')||(rr>='D' && cr>='D');
	bool p = 0;
	if (rr > cr && rr-cr==1) p=1;
	else if (cr>rr && cr-rr==1) p = 1;
	cout << (t0&&t?1:0) << (t0&&t&&p?1:0);
	return 0;
}
