clude <bits/stdc++.h>
using namespace std;
struct node
{
    long long num;
    char c;
};
node a[200005],b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt = 0,sum = 0,na = 1,nb = 1;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i].num >> a[i].c;
        b[n-i+1].num  = a[i].num;
        b[n-i+1].c = a[i].c;
        sum+=a[i].num;
    }
    sum /= 2;
    while(sum>0)
    {
        if(a[na].c == b[nb].c)
        {
            if(a[na].num<b[nb].num)
            {
                sum = sum-a[na].num;
                b[nb].num = b[nb].num-a[na].num;
                a[na].num = 0;
            }
            else if(a[na].num == b[nb].num)
            {
                sum = sum-a[na].num;
                a[na].num = 0;
                b[nb].num = 0;
            }
            else if(a[na].num > b[nb].num)
            {
                sum = sum-b[nb].num;
                a[na].num = a[na].num-b[nb].num;
                b[nb].num = 0;
            }
            if(a[na].num == 0)
            {
                na++;
            }
            if(b[nb].num == 0)
            {
                nb++;
            }
        }
        else
        {
            if(a[na].num<b[nb].num)
            {
                cnt = cnt+a[na].num;
                sum = sum-a[na].num;
                b[nb].num = b[nb].num-a[na].num;
                a[na].num = 0;
            }
            else if(a[na].num == b[nb].num)
            {
                cnt = cnt+a[na].num;
                sum = sum-a[na].num;
                a[na].num = 0;
                b[nb].num = 0;
            }
            else if(a[na].num > b[nb].num)
            {
                cnt = cnt+b[nb].num;
                sum = sum-b[nb].num;
                a[na].num = a[na].num-b[nb].num;
                b[nb].num = 0;
            }
            if(a[na].num == 0)
            {
                na++;
            }
            if(b[nb].num == 0)
            {
                nb++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}