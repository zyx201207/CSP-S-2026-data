#include<bits/stdc++.h>
using namespace std;
const int M = 3e5 + 5;
int n , m;
int a[M];
int main()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    	cin >> a[i]; 
    cout << n << " ";
    for(int i = n - 1 ; i >= 1 ; i--)
    {
    	if(a[i] == a[i + 1])
    		cout << 0 << " ";
		else
			cout << i << " "; 
	}
    return 0;
}
