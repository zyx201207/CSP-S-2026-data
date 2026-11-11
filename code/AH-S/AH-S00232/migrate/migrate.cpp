#include <bits/stdc++.h>
using namespace std;

inline int read ()
{
	int x = 0;
	bool f = 0;
	char c = getchar ();
    for (; c < '0' || c > '9'; c = getchar ()) if (c == '-') f = 1;
    for (; c >= '0' && c <= '9'; c = getchar ())
       x = x * 10 + c - '0';
    return f? -x : x;
}
int a, b;
int main ()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    srand ((unsigned) time(NULL));
    cin >> a >> b;
    for (int i = 1; i <= b; i++ ) printf ("%d\n", rand() % 1000);
    return 0;
}
