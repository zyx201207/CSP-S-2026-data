#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
#define lop(a,b,c) for (int a = b ; a <= c ; ++a)
#define x first
#define y second
using namespace std;
pair<int,int> p[200005];
struct node{
    int x,y,ch;
} a[200005],b[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,cnt=0,c1,c2,tot=0;
    char ch;
    cin >> n;
    loop(i,n)
    {
        cin >> c1 >> ch;
        c2=(int)ch;
        tot+=c1;
        if (c2==p[cnt].x)
        {
            p[cnt].y+=c1;
        } else {
            p[++cnt].x=c2;
            p[cnt].y=c1;
        }
    }
    int sum=0,n1=0,n2=0;
    loop(i,cnt)
    {
        if (sum==tot/2) break;
        if (sum+p[i].y>tot/2) 
        {
            a[i]={sum+1,tot/2,p[i].x};
            n1=i;
            break;
        }
        a[i]={sum+1,sum+p[i].y,p[i].x};
        sum+=p[i].y;
        n1=i;
    }
    sum=0;
    loop(i,cnt)
    {
        if (sum==tot/2) break;
        if (sum+p[cnt-i+1].y>tot/2) 
        {
            b[i]={sum+1,tot/2,p[cnt-i+1].x};
            n2=i;
            break;
        }
        b[i]={sum+1,sum+p[cnt-i+1].y,p[cnt-i+1].x};
        n2=i;
        sum+=p[cnt-i+1].y;
    }
    // loop(i,n1)
    // {
    //     cout << a[i].x << " " << a[i].y << " " << char(a[i].ch) << endl;
    // }
    // cout << endl;
    // loop(i,n2)
    // {
    //     cout << b[i].x << " " << b[i].y << " " << char(b[i].ch) << endl;
    // }
    // cout << endl;
    int r=1,ans=0,mx=0;
    loop(l,n1)
    {
        while (r<=n2&&b[r].y<=a[l].y)
        {
            if (a[l].ch!=b[r].ch)
            {
                ans+=min(a[l].y,b[r].y)-max(a[l].x,b[r].x)+1;
            }
            r++;
        }
        if (b[r].y>a[l].y)
        {
            if (a[l].ch!=b[r].ch)
            {
                ans+=min(a[l].y,b[r].y)-max(a[l].x,b[r].x)+1;
            }
        }
    }
    cout << ans << endl;
	return 0;
}

