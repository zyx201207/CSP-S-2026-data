#include<bits/stdc++.h>
using namespace std;
int a[200005],n,ans;
long long w=1,sum,fw,sg;
char c[200005];
string s,zs;
struct st
{
    int sr,en;
    char ch;
} q[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    q[0].sr=0;
    q[0].en=0;
    q[n+1].en=2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        q[i].sr=q[i-1].en+1;
        q[i].en=q[i].sr+a[i]-1;
        q[i].ch=c[i];
        sum+=a[i];
    }
    fw=n;
    for(int i=1;i<=sum/2;i++)
    {
        if(q[w].ch!=q[fw].ch) ans++;
        if(i==q[w].en) w++;
        if(i==sg+(q[fw].en-q[fw].sr+1))
        {
            sg+=q[fw].en-q[fw].sr+1;
            fw--;
        }
    }
    cout<<ans;
    return 0;
}
