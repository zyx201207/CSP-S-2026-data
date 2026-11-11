#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],m = 0;
char c[200010];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cin >> c[i];
        for(int j=0;j<a[i];j++)
		{
			s += c[i];
		}
    }
    int k = s.size();
	for(int i=0;i<k/2;i++)
    {
        if(a[i]!= a[k+1-i])
        {
			a[k+1-i] = a[i];
			m++;
		}
    }
    cout << m;
    return 0;
}
