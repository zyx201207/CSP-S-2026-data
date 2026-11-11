#include <bits/stdc++.h>
#define int long long
#define gc getchar
using namespace std;

int Miku(){
	int k = 0,f = 1,c = gc();
	for (;!isdigit(c);c = gc()) if (c == '-') f = -1;
	for (;isdigit(c);c = gc()) k = k * 10 + (c ^ 48);
	return k * f;
}



signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	
	
	return 0;
}
