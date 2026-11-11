#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char b[1000005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n; cin>>n;
    int tot = 0;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        tot += a[i];
    }
    deque<char> c;
    int num = 0;
    for(int i = 1;i<=n;i++)
    {
		for(int j = 1;j<=a[i];j++)
		{
			num ++;
			c[num] = b[i];
		}
	}
	int xx = 0;
	int l = 1;
	int r = tot;
	for(int i = 1;i<=tot/2;i++)
	{
		if(r < l) break;
		if(c[l] != c[r]) xx++;
		l++; r--;
	}
	cout<<xx;
    return 0;
}
