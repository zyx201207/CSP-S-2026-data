#include <bits/stdc++.h>
using namespace std;
int a[200555];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int ans = 0;
    cin >>n>>m;
    for (int i = 0;i<n;i++)
    {
        cin >>a[i];
    }
    if (m==1)
    {
        for (int i = 0;i<n;i++)
        {
            ans = max(ans,a[i]);
        }
        cout <<ans;
        return 0;
    }
    if (m==2)
    {
        for (int i = 0;i<n;i++)
        {
            for (int j = i+1;j<n;j++)
            {
                int pan = a[i]&a[j];
                ans = max(ans,pan);
            }
        }
        cout <<ans;
        return 0;
    }
    if (n == m)
    {
        for (int i = 0;i<n;i++)
        {
            ans = ans&a[i];
        }
        cout <<ans;
        return 0;
    }
    //shi+++++++++++++++++++++++++++++++++++++++++
    if (n>=m)
    {
        if (m==3)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        int pan = a[i]&a[j]&a[p];
                        ans = max(ans,pan);
                    }
                }
            }
            cout <<ans;
        }
        if (m==4)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        for (int pp = p+1;pp<n;pp++)
                        {
                            int pan = a[i]&a[j]&a[p]&a[pp];
                            ans = max(ans,pan);
                        }
                    }
                }
            }
            cout <<ans;
        }
        if (m==5)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        for (int pp = p+1;p<n;pp++)
                        {
                            for (int ppp=pp+1;p<n;ppp++)
                            {
                                int pan = a[i]&a[j]&a[p]&a[pp]&a[ppp];
                                ans = max(ans,pan);
                            }
                        }
                    }
                }
            }
            cout <<ans;
        }
        if (m==6)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        for (int pp = p+1;pp<n;pp++)
                        {
                            for (int ppp=pp+1;ppp<n;ppp++)
                            {
                                for (int pppp = ppp+1;pppp<n;pppp++)
                                {
                                    int pan = a[i]&a[j]&a[p]&a[pp]&a[ppp]&a[pppp];
                                    ans = max(ans,pan);
                                }
                            }
                        }
                    }
                }
            }
            cout <<ans;
        }
        if (m==7)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        for (int pp = p+1;pp<n;pp++)
                        {
                            for (int ppp=pp+1;ppp<n;ppp++)
                            {
                                for (int pppp = ppp+1;pppp<n;pppp++)
                                {
                                    for (int io = pppp+1;io<n;io++)
                                    {
                                        int pan = a[i]&a[j]&a[p]&a[pp]&a[ppp]&a[pppp]&a[io];
                                        ans = max(ans,pan);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout <<ans;
        }
        if (m==8)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        for (int pp = p+1;pp<n;pp++)
                        {
                            for (int ppp=pp+1;ppp<n;ppp++)
                            {
                                for (int pppp = ppp+1;pppp<n;pppp++)
                                {
                                    for (int io = pppp+1;io<n;io++)
                                    {
                                        for (int io1=io+1;io1<n;io1++)
                                        {
                                            int pan = a[i]&a[j]&a[p]&a[pp]&a[ppp]&a[pppp]&a[io]&a[io1];
                                            ans = max(ans,pan);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout <<ans;
        }
        if (m==9)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        for (int pp = p+1;pp<n;pp++)
                        {
                            for (int ppp=pp+1;ppp<n;ppp++)
                            {
                                for (int pppp = ppp+1;pppp<n;pppp++)
                                {
                                    for (int io = pppp+1;io<n;io++)
                                    {
                                        for (int io1=io+1;io1<n;io1++)
                                        {
                                            for (int io2=io1+1;io2<n;io2++)
                                            {
                                                int pan = a[i]&a[j]&a[p]&a[pp]&a[ppp]&a[pppp]&a[io]&a[io1]&a[io2];
                                                ans = max(ans,pan);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout <<ans;
        }
        if (m==10)
        {
            for (int i = 0;i<n;i++)
            {
                for (int j= i+1;j<n;j++)
                {
                    for (int p = j+1;p<n;p++)
                    {
                        for (int pp = p+1;pp<n;pp++)
                        {
                            for (int ppp=pp+1;ppp<n;ppp++)
                            {
                                for (int pppp = ppp+1;pppp<n;pppp++)
                                {
                                    for (int io = pppp+1;io<n;io++)
                                    {
                                        for (int io1=io+1;io1<n;io1++)
                                        {
                                            for (int io2=io1+1;io2<n;io2++)
                                            {
                                                for (int io3 = io2+1;io3<n;io3++)
                                                {
                                                    int pan = a[io3]&a[i]&a[j]&a[p]&a[pp]&a[ppp]&a[pppp]&a[io]&a[io1]&a[io2];
                                                    ans = max(ans,pan);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout <<ans;
        }
    }
    return 0;
}
