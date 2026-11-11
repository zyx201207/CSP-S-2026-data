#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f = true;
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a == c) cout << 1;
	else cout << 0;
	char b_wei = b[2];
	char d_wei  = d[2];
	int numb = b[0] + b[1];
	int numd = d[0] + d[1];
	if (a == c)
    {
        if (numb == numd)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }
    if (a == c && numb == numd)
    {
        if ('A' <= b_wei && b_wei <= 'C')
        {
            if ('A' <= d_wei && d_wei <= 'C')
            {
                cout << 1;
            }
            else
            {
                cout << 0;
                f = false;
            }
        }

        else if('D' <= b_wei && b_wei <= 'F')
        {
            if ('D' <= b_wei && b_wei <= 'F')
            {
                cout << 1;
            }
            else
            {
                cout << 0;
                f = false;
            }
        }
    }
    else
    {
        cout << 0;
        f = false;
    }
    if (a == c && numb == numd && f == true)
    {
        if (max(b_wei,d_wei) - min(b_wei,d_wei) == 1)
        {
            cout << 1;
        }
        else
        {
            cout <<0;
        }
    }
    else
    {
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
