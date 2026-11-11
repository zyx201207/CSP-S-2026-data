#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c,b,d;
	cin >> a >> b >> c >> d;
	if (a!=c) cout << 0 << 0 << 0 << 0;
	else{
		if(b[0]!=d[0]||b[1]!=d[1]) cout << 1<<0<<0<<0;
		else{
			if (b[2]<68&&d[2]>67||b[2]>67&&d[2]<68) cout << 1<<1<<0<<0;
			else{
				if (b[2]>67) cout << 1<<1<<1<<1;
				else if (b[2]==66||d[2]==66) cout << 1<<1<<1<<1;
				else cout << 1<<1<<1<<0;
			}
		}
	}
	return 0;
}
