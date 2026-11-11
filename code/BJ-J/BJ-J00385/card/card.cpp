#include<bits/stdc++.h>
using namespace std;
set<int>s;
int n,m,a[500010],tong[300010],cs[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    if(s.size()==n)
    {
        for(int i = 1;i<=n;i++)
        {
            cout<<i<<" ";//ce shi dian 15,16,17
        }
        return 0;
    }
    for(int i = 1;i<=n;i++)//ce shi dian 1,2,3
    {
        int ma = 1;
        memset(tong,0,sizeof(tong));
        for(int j = i;j<=n;j++)
        {
            if(tong[a[j]]!=0)
            {
                for(int k = 1;k<=m;k++)
                {
                    if(tong[k]>tong[a[j]])
                    {

                        tong[k]=0;
                        ma--;
                    }
                }
            }
            else{
                tong[a[j]]=ma;
                ma++;
            }
        }
        for(int j = 1;j<=m;j++)
        {
            if(tong[j]!=0)
            {
                cs[j]++;
            }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        cout<<cs[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//gu fen 100+100+8+24=232
