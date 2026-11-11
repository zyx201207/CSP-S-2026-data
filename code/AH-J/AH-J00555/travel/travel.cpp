#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    char e=b[2],f=d[2];
    if (a == b)
    {
        cout << '1';
        if (b[0]== d[0] && b[1] == d[1])
        {
            cout << '1';
            if(e<=f && f<= "b")
            {
                if(e>= "c" && f>= e)
                {
                    cout << '1';
                    if (abs(e-f)==1)
                    {
                        cout << '1';
                    }
                    else{
                        cout << '0';
                    }
                }
            else
            {
                cout << '00';
            }
    else
    {
        cout<<'0000';
	}
    return 0;
}
