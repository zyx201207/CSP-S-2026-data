#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num;
    char c;
};
const int N=2e5+5;
int n;
node a[N];
vector<node>q;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].c;
        sum+=a[i].num;
    }
    int len=0;
    for(int i=1;i<=n;i++)
    {
        if(len+a[i].num<n/2)
        {
            q.push_back(a[i]);
            len+=a[i].num;
        }
        q.push_back({n/2-len,a[i].c});
        q.push_back({a[i].num+len-n/2,a[i].c});
    }
    int l=0,r=q.size()-1;
    long long change=0;
    while(l<r)
    {
        if(a[l].num>a[r].num)
        {
            a[l].num-=a[r].num;
            if(a[l].c!=a[r].c) change+=a[r].num;
            r--;
        }
        else if(a[l].num<a[r].num)
        {
            a[r].num-=a[l].num;
            if(a[l].c!=a[r].c) change+=a[l].num;
            l++;
        }
        else
        {
            if(a[l].c!=a[r].c) change+=a[l].num;
            l++,r--;
        }
    }
    cout<<change<<endl;
    return 0;
}
//1st csp! rp++