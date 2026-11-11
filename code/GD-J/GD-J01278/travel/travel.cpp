#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
#define lop(a,b,c) for (int a = b ; a <= c ; ++a)
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int cx,cy,px,py,zx,zy;
    string a,b;
    cin >> cx >> a >> cy >> b;
    px=(a[0]-'0')*10+a[1]-'0';
    py=(b[0]-'0')*10+b[1]-'0';
    zx=a[2]-'A'+1;
    zy=b[2]-'A'+1;
    if (cx==cy)
    {
        cout << "1";
        if (px==py)
        {
            cout << "1";
            if ((zx>=1&&zx<=3&&zy>=1&&zy<=3)||(zx>=4&&zx<=5&&zy>=4&&zy<=5))
            {
                cout << "1";
                if (abs(zx-zy)==1)
                {
                    cout << "1";
                } else cout << "0";
            } else cout << "00";
        } else cout << "000";
    }else cout << "0000";
	return 0;
}
