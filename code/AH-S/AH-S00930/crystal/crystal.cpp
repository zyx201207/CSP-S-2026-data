#include <iostream>
#include <algorithm>
using namespace std;

const int N=5*1e5+5,T=1e9;

long long cun[N];
long long n,m,i,t=0,j,maxn=0,all=1,cha;//n is 数量// m is 最多操作//all是总的最大和成数量//maxn是每次加成的最大值
//t 是每次的最大值
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(nullptr);

    cin >> n >> m;
    if(m >= T)
    {
        for(i=1 ;i<=n; i++)//输入
        {
            cin >> cun[i];
        }
        sort(cun+1, cun+n+1);
        cha=cun[2]-cun[1];
        for(i=1; ; i++)
        {
            if( (cha + cha*i) * i / 2 > m)
            {
                all=max(all, i-1);
                break;
            }
        }
        cout<<all;
    }
    else
    {
        for(i=1 ;i<=n; i++)//输入
        {
            cin >> cun[i];
        }
        sort(cun+1, cun+n+1);//排序

        for(i=1; i<=n; i++)
        {
            for(j=i; j>=1; j--)
            {
                maxn+=cun[i] - cun[j];
                if(maxn > m) break;
                t++;
            }
            all= max(t, all);
            maxn=0;
            t=0;
        }
        cout<<all;
    }

    return 0;
}

