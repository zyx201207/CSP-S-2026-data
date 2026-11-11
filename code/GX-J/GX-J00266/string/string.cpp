#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x=0;
	cin >> n;
	long long a[n+5];
	char c[n+5];
	for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        x=x+a[i];
    }
	char s[x+5];
	for(int i=1;i<=n;i++){
        int k=1;
		for(int j=1;j<=a[i];j++){
            s[k]=c[i];
            k++;
		}
	}
	long long cnt=0;
	for(int i=1;i<=x/2;i++)
	{
        if(s[i]!=s[x-i+1]) cnt++;
        else cnt+=0;
	}
	cout << cnt;
	return 0;
}
