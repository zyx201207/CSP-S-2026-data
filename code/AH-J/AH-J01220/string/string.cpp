#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200055],b[200055],d,t,e[100055],f[100055];
unsigned long long ans;
int n;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c;
        b[i]=c;
        d+=a[i];
    }//读入
    unsigned long long w=d/2;
    if(w*2!=d)
        w++,t=1;//判断奇数长度，减去中间
        unsigned long long q=w,p=1,s=0;
        if(t!=0)
            q--;
        while(q>0)//前半段
        {
            if(a[p]>q)//到达边界
                e[++s]=q,f[s]=b[p],a[p]-=q,q=0;
            else//未到边界
                e[++s]=a[p],f[s]=b[p],q-=a[p],p++;
        }
        if(t!=0)
        {
            a[p]--;
            if(a[p]==0)
                p++;
        }
        while(s>0)//后半段比较
        {
            if(b[p]==f[s])//相同字符
            {
                if(a[p]>e[s])
                    a[p]-=e[s],s--;
                else
                {
                    if(a[p]==e[s])
                        s--,p++;
                    else
                        e[s]-=a[p],p++;
                }
            }
            else//不同字符
            {
                if(a[p]>e[s])
                    ans+=e[s],a[p]-=e[s],s--;
                else
                {
                    if(a[p]==e[s])
                        ans+=a[p],s--,p++;
                    else
                        ans+=a[p],e[s]-=a[p],p++;
                }
            }
        }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
