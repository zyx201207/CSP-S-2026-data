#include<bits/stdc++.h>
using namespace std;
#define mj long long
#define mk string 
struct Node{
	mj nn;mk s;
};
mj n , cnt;
Node q[10000000];
bool b = 1;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> q[i].nn >> q[i].s , cnt += q[i].nn;
	cout << cnt / 2;
} 
