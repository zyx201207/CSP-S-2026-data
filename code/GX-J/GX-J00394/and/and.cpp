#include<bits/stdc++.h>
using namespace std;
int n,m,biggest=0;
int num[200010];
/*int totwo(int x)
{
    bool ans[20000000010];
    while(x>1)
    {
        ans[i]=x%2;
        i++;
        x/=2;
    }

}*/
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(num,0,sizeof(num));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            biggest=max(num[i],biggest);
            //cout<<biggest<<endl;
        }
        cout<<biggest;
    }
    return 0;
}
