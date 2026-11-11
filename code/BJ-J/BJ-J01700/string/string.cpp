#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
struct node{
    long long z;
    char c;
};
deque<node> q;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i = 1;i<=n;i++)
    {
        long long a=0;
        char z=0;
        cin>>a>>z;
        q.push_back({a,z});
        //cout<<q.back().z<<endl;
    }
    while(q.size()>1)
    {
        node f = q.front();
        node b = q.back();
        //cout<<f.z<<" "<<b.z<<" || ";
        q.pop_front();
        q.pop_back();
        if(f.c==b.c)
        {
            //cout<<" =  "<<f.z<<" "<<b.z<<endl;
            if(f.z>b.z)
            {
                //cout<<b.z<<" "<<f.z<<endl;
                f.z-=b.z;
                q.push_front({f.z,f.c});
            }
            else if(f.z<b.z)
            {
                //cout<<b.z<<" "<<f.z<<" |2| ";
                b.z-=f.z;
                q.push_back({b.z,b.c});
                //cout<<b.z<<" "<<b.c<<endl;
            }
        }
        else
        {
            //cout<<" != "<<f.z<<" "<<b.z<<endl;
            if(f.z>b.z)//wrong
            {
                f.z-=b.z;
                //cout<<b.z<<endl;
                ans+=b.z;
                q.push_front({f.z,f.c});
                //cout<<f.z<<" ";
            }
            else if(f.z==b.z)
            {
                ans += b.z;
                //cout<<b.z<<endl;
            }
            else
            {
                //cout<<b.z<<" "<<f.z<<" |1| ";
                b.z-=f.z;
                ans+=f.z;
                //cout<<f.z<<endl;
                q.push_back({b.z,b.c});
                //cout<<b.z<<" "<<b.c<<endl;
                //cout<<b.z<<" ";
            }
        }
        //cout<<ans<<" ";
    }
    cout<<ans;
    return 0;
}