#include  <iostream>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    bool f1,f2,f3,f4;
    f1=f2=f3=f4=0;
    char x =  b[2],y=d[2];
    if(y > x)
    {
        swap(x,y);
    }
    if (a == c)
    {
        f1 = 1;
        if (b[0] ==  d[0] && b[1] == d[1])
        {
            f2 = 1;
            if ((b[2] <= 'C'&& d[2] <= 'C') || (b[2] > 'C'&& d[2] > 'C'))
            {
                f3 = 1;
                ++y;
                if (x == y)
                {
                    f4=1;
                }
            }
        }
    }
    cout << f1 << f2 << f3 << f4;
    return 0;
}