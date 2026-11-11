#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010],b[500010],l=-1,num[300010];
struct q
{
    int w=0,c=1e9;
}v[500010];
void f(int x)
{
    l++;
    if(v[x].w)
    {
        int s = v[x].c+1;
        for(int i=s-1;i<l;i++)
		{
			v[b[i]].w=0;
			b[i] = 0;
		}
		l = s;
    }
    else{
        v[x].c = l;
    }
    v[x].w=1;
    b[l] = x;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            b[i] = 0;
            v[i].w = 0;
            v[i].c = 0;
        }
        for(int i=k;i<n;i++)
        {
            f(a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            num[i] += v[i].w;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << num[i] << ' ';
    }
    return 0;
}
