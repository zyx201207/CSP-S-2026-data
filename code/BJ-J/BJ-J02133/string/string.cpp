#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
struct node
{
    long long u, d;
    char a;
};
node s1[2000005];
node s2[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int b[200005], bl,cntb = 0,cntc = 0;
    long long sum = 1, sum1 = 0;
    char c[200005], cl;
    for(int i = 1;i <= n;i++)
    {
        cntb++;
        cntc++;
        cin >> b[cntb] >> c[cntb];
        sum += cntb;
        if(c[cntc] == cl)
        {
            cntc--;
            cntb--;
            b[cntb] += b[cntb+1];
            b[cntb+1] = 0;

        }
        cl = c[cntc];
        bl = b[cntb];
    }
    long long cnt = 0;
    int cnts1=0, cnts2=0;
    for(int i = 1;i <= n;i++)
    {
        cnts1 ++;
        if(cnt+b[i] < sum/2-1)
        {
            s1[cnts1].u = cnt+1;
            s1[cnts1].d = cnt+b[i];
            s1[cnts1].a = c[i];
            cnt += b[i];
            //cout << s1[cnts1].u << " " << s1[cnts1].d << s1[cnts1].a << " " << endl;
        }
        else
        {
            s1[cnts1].u = cnt+1;
            s1[cnts1].d = sum/2-1;
            s1[cnts1].a = c[i];
            cnt = sum /2-1;
            break;
        }
    }
    cnt = sum;
    for(int i = n;i >= 1;i--)
    {
        cnts2 ++;
        if(cnt-b[i] > (sum+1)/2+1)
        {
            s2[cnts2].u = cnt-1;
            s2[cnts2].d = cnt-b[i];
            s2[cnts2].a = c[i];
            cnt -= b[i];
            //cout << s2[cnts2].u << " " << s2[cnts2].d << s2[cnts2].a << " " <<cnt << " " << cnts2<< endl;
        }
        else
        {
            s2[cnts2].u = cnt;
            s2[cnts2].d = (sum+1)/2+1;
            s2[cnts2].a = c[i];
            cnt = (sum+1)/2+1;
            break;
        }
    }
    cout << cnts1 << cnts2;
    int r =s1[1].d,l =s2[1].d;
    int cntr = 1, cntl = 1;
    while(cntr <= cnts1&&cntl <= cnts2)
    {
        if(r >= sum - l)
        {
            if(s1[cntr].a != s2[cntl].a)
            {
                sum1+=r - (sum-l);
            }
            r -= r - (sum - l);
            l -= r - (sum - l);
            cntl++;
            l += s2[cntl].d-l;
        }
        if(r < sum - l)
        {
            if(s1[cntr].a != s2[cntl].a)
            {
                sum1+=(sum-l) - r;
            }
            r -= (sum-l) - r;
            l -= (sum-l) - r;
            cntr++;
            r += s1[cntr].d-r;
        }
    }
    cout << sum1;
}
