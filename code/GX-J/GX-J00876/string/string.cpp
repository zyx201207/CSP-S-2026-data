#include <bits/stdc++.h>
using namespace std;
long long ans,len=0;
int a[200004];
char c[200004];
bool flag = 1;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i =1;i <= n;i++)
    {

        cin >> a[i] >> c[i];
        len+=a[i];
        if(!(c[i] == c[i-1]))
        {
            flag = 0;
        }
    }
    if(flag)
    {
        cout << 0;
        return 0;
    }
    //cout << len << " ";
    bool flag2 = 1;
    int tot,targ;
    long long len1=0;
    for(int i =1;i <= n;i++)
    {
        len1 += a[i];
        //cout << len1 <<" " << len/2 << endl;
        if(len1 == len/2)
        {
            //cout << len1 << endl;
            flag2 = 0;
            break;
        }
        else if(len1 > len/2)
        {
            tot = i;
            targ = len1 - len/2;
            break;
        }
    }
    int l=1,r=n;
    if(flag2)
    {
        r++;
        for (int i = n+1;i >= tot+2;i--)
        {
            a[i]=a[i-1];
            c[i]=c[i-1];
        }
        a[tot+1] = targ;c[tot+1]=c[tot];
        a[tot] -= targ;
    }
    int num=0;
    char res='#';
    int numl = a[l],numr = a[r];
    bool cm =0;
    while(l<=r)
    {
        if(numl > numr)
        {
            if(c[l] != c[r])
            {
                ans += numr;
            }
            numl -= numr;
            r--;
            numr = a[r];
        }
        else if(numl < numr)
        {
            if(c[l] != c[r])
            {
                ans += numl;
            }
            numr -= numl;
            l++;
            numl = a[l];
        }
        else
        {
            if(c[l] != c[r])
            {
                ans += numl;
            }
            r--,l++;
            numl = a[l],numr = a[r];
        }
    }
    cout << ans;
    return 0;
}
