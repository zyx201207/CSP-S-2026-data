#include<bits/stdc++.h>
using namespace std;
int n,m,t;
long long sum;
int maxx=0xfffffff;
struct ww
{
    int x;
    char y;
};
ww b[1000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n==1)
	{
        cout << "0";
	    return 0;
	}
	for(int i=1; i<=n; i++)
	cin >> b[i].x >> b[i].y;

	for(int i=1; i<=n; i++)
        if(b[i].y != b[i+n/2].y || b[i].y != b[i+n/2+1].y)
        {
            if(b[i].x%2==0)
                sum += b[i].x;
            else
            {
                m++;
                sum += b[i].x-1;
                if(b[i].x>maxx)
                    maxx = b[i].x;
            }
        }

	for(int i=1; i<=n; i++)
    {
        if(b[i].y!=b[i+1].y)
        {
            if(m%2==0)
                cout << sum/2;
            else
                cout << (sum-maxx)/2;
            return 0;
        }
        else
        {
            cout << "0";
            return 0;
        }
    }
    return 0;
}
