#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
    int num;
    char ch;
}a[N];
int n,ans;
vector<char> err;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        getchar();
        cin>>a[i].ch;
    }
    for(int i=1,j=n;i<j;)
    {
        if(a[i].num<a[j].num)
        {
            a[j].num-=a[i].num;
            if(a[i].ch!=a[j].ch)
                ans+=a[i].num;
            i++;
            continue;
        }
        if(a[i].num==a[j].num)
        {
            if(a[i].ch!=a[j].ch)
                ans+=a[i].num;
            i++,j--;
            continue;
        }
        if(a[i].num>a[j].num)
        {
            err.clear();
            int o=j,ty=0;
            while(ty<a[i].num)
            {
                ty+=a[j].num;
                err.push_back(a[j].ch);
                j--;
            }
            if(ty<a[i].num)
            {
                for(auto k:err)
                {
                    if(k!=a[i].ch)
                        ans+=a[o].num;
                    o--;
                }
                cout<<ans<<endl;
                return 0;
            }
            j++;
            if(ty>a[i].num)
                a[j].num=a[j].num-ty+a[i].num;
            for(auto k:err)
            {
                if(k!=a[i].ch)
                    ans+=a[o].num;
                o--;
            }
            if(ty>a[i].num)
                a[j].num=ty-a[i].num,i++;
            if(ty==a[i].num)
                i++,j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
