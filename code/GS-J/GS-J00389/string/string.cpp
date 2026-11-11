#include<iostream>
using namespace std;
long long a[1000000000];
char c[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    string x;
    int sum = 0;
    int y = 0,f;
	int l,r;
    for(int i = 0;i < n;i++)
    {
    	cin >> a[i] >> c[i];
		for(int b = 0;b < a[i];b++)
		{
		   	x += c[i];
		}   
		y += a[i];
		l = y / 2 - 1;
		r = l + 2;
	} 
	for(int i = 0;i < n;i++)
	{
		 if(x[l] != x[r])
		 {
		 	sum++;
		 }
		 l--;
		 r++;
	}
	// a a a a a
	// 0 1 2 3 4
	cout << sum;
	return 0;
}
