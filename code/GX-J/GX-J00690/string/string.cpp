#include <bits/stdc++.h>

using namespace std;
struct zf
{
    long long n;
    char w;
};
queue<zf> s;
zf a[200005];
char jl;
int n;
int si=1;
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //cout << "Hello world!" << endl;
    zf t;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t.n>>t.w;
        if(t.w==a[si].w)
        {
            a[si].n+=t.n;
        }
        else
        {
            si++;
            a[si]={t.n,t.w};
        }
    }
    for(int i=1,j=si;i<j;)
    {
        if(s.size()>0)//queue
        {
            t=s.front();
            if(jl=='j')
            {
                if(t.n>a[j].n)
                {
                    s.push({t.n-a[j].n,t.w});
                    ans+=a[j].n;
                    j--;
                    jl='j';
                }
                else if(t.n<a[j].n)
                {
                    s.push({a[j].n-t.n,a[j].w});
                    ans+=t.n;
                    i++;
                    jl='i';
                }
                else
                {
                    ans+=t.n;
                    i++;
                    j--;
                }
            }
            else
            {
                if(t.n>a[i].n)
                {
                    s.push({t.n-a[i].n,t.w});
                    ans+=a[i].n;
                    i--;
                    jl='i';
                }
                else if(t.n<a[i].n)
                {
                    s.push({a[i].n-t.n,a[i].w});
                    ans+=t.n;
                    j++;
                    jl='j';
                }
                else
                {
                    ans+=t.n;
                    i++;
                    j--;
                }
            }
        }
        else if(a[i].w!=a[j].w)//a!=b
        {
            if(a[i].n>a[j].n)
            {
                s.push({a[i].n-a[j].n,a[i].w});
                ans+=a[j].n;
                j--;
                jl='j';
            }
            else if(a[i].n<a[j].n)
            {
                s.push({a[j].n-a[i].n,a[j].w});
                ans+=a[i].n;
                i++;
                jl='i';
            }
            else
            {
                ans+=a[i].n;
                i++;
                j--;
            }
        }
        else//a==b
        {
            if(a[i].n>a[j].n)
            {
                s.push({a[i].n-a[j].n,a[i].w});
                j--;
                jl='j';
            }
            else if(a[i].n<a[j].n)
            {
                s.push({a[j].n-a[i].n,a[j].w});
                i++;
                jl='i';
            }
            else
            {
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
