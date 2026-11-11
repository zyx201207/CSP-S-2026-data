#include<bits/stdc++.h>
#include<deque>
using namespace std;
int main()
{
    freopen("string.in");
    freopen("string.out");
    int n,d,cnt=0;
    char a;
    deque q;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        cin>>d>>a;
        for(int i=1;i<=d;i++)
        {
            q.push_back(a);
        }
    }
    for(int i=1;i<=q.size();i++)
    {
        if(q.front()!=q.back())
        {
            cnt++;
            q.pop_front();
            q.pop_back();
        }
    }
    cout<<cnt;
    return 0;
}
