//GZ-J00045 ¸¶³¿³©
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;cin>>a>>b>>c>>d;
	long long h1 = 0,h2 = 0;
	for(int i = 0;i<a.size();++i) {
	    h1= h1*10+(a[i]-48);
	    h2= h2*10+(c[i]-48);
	}
	if (h1 == h2) {
		cout<<1;
		if (b[0] == d[0] && b[1] == d[1]) {cout<<1;
		    if (( b[2] == 'A' && (d[2] == 'B'|| d[2] == 'C')) || ( b[2] == 'B' && (d[2] == 'A'|| d[2] == 'C')) || ( b[2] == 'C' && (d[2] == 'B'|| d[2] == 'A')) || (b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')) {
			    cout<<1;
			    if (abs(b[2] - d[2])==1 && !(b[2] == 'C' && d[2] == 'D') && !(b[2] == 'C' && d[2] == 'D')) cout<<1;
			    else {cout<<"0";return 0;}
			}else {cout<<"00";return 0;}
		}
		else {cout<<"000";return 0;}
	}
	else cout<<"0000";
    return 0;
}
