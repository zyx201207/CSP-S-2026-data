#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,m,sum1,sum2;
int pos[3];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    a.push_back(0);
    pos[0] = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp != pos[i-1]) pos[i] = tmp;
        bool flag = true;
        for(int j = i-1;j >= 0;j--)
        {
            if(a[j] == tmp)
            {
                flag = false;
                break;
            }
        }
        if(flag) a.push_back(tmp);
        else
        {
            while(a.size()!=1) a.pop_back();
            a.push_back(tmp);
        }
        for(int i = 1;i < a.size();i++)
        {
            if(a[i]==pos[1]) sum1++;
            if(a[i]==pos[2]) sum2++;
        }
    }
    cout << sum1 << " " << sum2;
    return 0;
}

