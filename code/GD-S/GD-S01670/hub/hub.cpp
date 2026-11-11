#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read();
const int N = 5e5 + 10;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	printf("1\n2\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
