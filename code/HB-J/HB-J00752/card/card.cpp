#include <bits/stdc++.h>
using namespace std;

int m,n;int pai[500002];int tong[500001],paicnt[500001],cnt;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>pai[i];
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)tong[i]=0;
        vector<int> zhuo;
        cnt=0;
        for(int ci=j;ci<=n;ci++)
        {
            if(tong[pai[ci]]!=0)
            {
                int i=1;
                while(tong[pai[ci]]<ci-cnt)
                {
                    tong[pai[ci-cnt]]=0;
                    paicnt[zhuo.back()]--;
                    cnt++;
                    zhuo.pop_back();
                }
            }
            else
                paicnt[pai[ci]]++;
            zhuo.push_back(pai[ci]);
            tong[pai[ci]]=ci;
        }
    }
    for(int i=1;i<=m-1;i++)cout<<paicnt[i]<<" ";
    cout<<paicnt[m];
    return 0;
}
