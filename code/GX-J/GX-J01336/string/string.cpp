#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    char c;
};
vector<node>v;
long long n,sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ai;
        char ci;
        cin>>ai>>ci;
        v.push_back({ai,ci});
    }
    int len=v.size();
    int cnti=0,cntj=len-1;
    while(cnti<=cntj)
    {
        cout<<cnti<<" "<<cntj<<endl;
        cout<<v[cnti].a<<" "<<v[cntj].a<<endl;
        cout<<v[cnti].c<<" "<<v[cntj].c<<endl;
        if(v[cnti].c==v[cntj].c)
        {
            if(v[cnti].a<v[cntj].a)
            {
                cnti++;
            }
            else if(v[cnti].a>v[cntj].a)
            {
                cntj--;
            }
            else
            {
                cnti++,cntj--;
            }
        }
        else
        {
            if(v[cnti].a<v[cntj].a)
            {
                sum+=v[cnti].a;
                v[cntj].a-=v[cnti].a;
                cnti++;
            }
            else if(v[cnti].a>v[cntj].a)
            {
                sum+=v[cntj].a;
                v[cnti].a-=v[cntj].a;
                cntj--;
            }
            else
            {
                sum+=v[cnti].a;
                cnti++,cntj--;
            }
        }
        cout<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
