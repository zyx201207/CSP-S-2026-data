#include <bits/stdc++.h>
using namespace std;
int a[400548];
int ji [400548];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >>n>>m;
    for (int i =0;i<n;i++)
    {
        cin >>a[i];
    }
    for (int i = 0;i<n;i++)
    {
        string s;
        string s1;
        for (int j = i;j<n;j++)
        {
            s+= to_string(a[j]);
        }
        for (int z= 0;z<s.size();z++)//
        {
            int l = z;
            int r = l+1;
            for (int y = z+1;y<s.size();y++)
            {
                if(s[l]==s[y])//y-1
                {
                    for (int r = z;r<y;r++)
                    {
                        s[r] = 'A';
                    }
                    l = y;
                }
            }
        }
        for (int b = 1;b<=m;b++)
        {
            for (int no = 0;no<s.size();no++)
            {
                string pans= to_string(b);
                if (s[no]==pans[0])
                {
                    ji[b]++;
                }
            }
        }
       // cout <<s<<'\n';
    }
    for (int i = 1;i<=m;i++)
    {
        cout <<ji[i]<<" ";
    }
    return 0;
}
