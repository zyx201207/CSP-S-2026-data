#include<bits/stdc++.h>
using namespace std;
deque<char> dq;
long long cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    if(n == 1)
    {
        long long x;
        char ch;
        cin >> x >> ch;
        cout << "0";
        return 0;
    }
        for(int i=1;i<=n;i++)
        {
            long long x;
            char ch;
            cin >> x >> ch;
            for(int j=1;j<=x;j++)
            {
                dq.push_back(ch);
            }
        }
        int len = dq.size();
        for (int i=1;i<=len;i++)
        {
            if(len%2==0)
            {
                if(!dq.empty())
                {
                    if(dq.front() != dq.back())
                    {
                        cnt++;
                        dq.pop_back();
                        dq.pop_front();
                    }
                }

            }
            else
            {
                if(!dq.empty() && dq.size() != 1)
                {
                    if(dq.front() != dq.back())
                    {
                        cnt++;
                        dq.pop_back();
                        dq.pop_front();
                    }
                }
            }
        }
    cout << cnt;
    return 0;
}

