#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[50005],cnt[50005],flag=0,num=1;
    //cout<<'1';
    vector<int> temp;
    //cout<<'1';
    cin>>n>>m;
    //cout<<'1';
    temp[0]=-1;
    for(int o=0;o<n;o++)
    {
        cin>>a[o];
    }
    //cout<<'1';
    for(int p=0;p<n;p++)
    {
        for(int i=0;i<n;i++)
        {
            flag=0;
            for(int j=0;j<=i;j++)
            {
                if(temp[j]==a[i])
                {
                    temp.clear();
                    flag=1;
                    num=1;
                    continue;
                }
            }
            if(flag==0)
            {
                temp[num-1]=a[num-1];
                num++;
            }
        }
        for(int q=0;q<num;q++)
        {
            cnt[temp[q]]++;
        }
        temp.clear();
        for(int k=1;k<n;k++)
        {
            a[k-1]=a[k];
        }
    }
    //cout<<'1';
    for(int l=0;l<m;l++)
    {
        cout<<cnt[l];
    }
    return 0;
}
