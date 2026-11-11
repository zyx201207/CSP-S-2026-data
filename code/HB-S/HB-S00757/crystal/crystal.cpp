#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long int> alist;
queue<long long int> que;
long long int m,n;

void init()
{
    cin>>n>>m;
    alist.resize(n+1,0);
    for(int i=1;i<=n;i++)cin>>alist[i];
    sort(alist.begin()+1,alist.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    init();

    long long int price=0;long long int maxnum = 0;int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(que.empty())
        {
            que.push(alist[i]);
            maxnum = alist[i];
        }
        if(alist[i]>maxnum)
        {
            price+=((int)que.size()*(alist[i]-maxnum));
            que.push(alist[i]);
            maxnum = alist[i];
            while(not que.empty() && price>m)
            {
                price-=(maxnum-que.front());
                que.pop();
            }
        }
        else que.push(alist[i]);
        ans = max(ans,(int)que.size());
    }
    //for(int i=1;i<=n;i++)cout<<alist[i]<<' ';
    //for(int i=1;i<lst.size();i++)cout<<lst[i].first<<' '<<lst[i].second<<'\n';
    cout<<ans;
}