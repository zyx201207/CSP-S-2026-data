//wo bu hui gai le
//wo pian le ce shi dian 6 and 7
#include<bits/stdc++.h>
using namespace std;
set<int>s;
int n,m,a[200010],f[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn = -1;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
        maxn=max(maxn,a[i]);
    }
    int teshu_7= a[1];
    for(int i = 2;i<=n;i++)
    {
        teshu_7=teshu_7&a[i];
    }
    if(m==1)//ce shi dian 6
    {
        cout<<maxn;
        return 0;
    }
    if(m==n)//ce shi dian 7
    {
        cout<<teshu_7;
        return 0;
    }
    if(s.size()==1)//ce shi dian 13
    {
        cout<<a[1];
        return 0;
    }
    //wo yi kai shi chang shi yong 01 bei bao zuo
    //but shi bai le
    for(int i = 1;i<=n;i++)
    {
        for(int j = m;j>=1;j--)
        {
            if(f[j-1]==0)
            {
                f[j]=max(f[j],f[j-1]+a[i]);
            }
            else{
                f[j]=max(f[j],f[j-1]&a[i]);
            }
        }
    }
    cout<<f[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
