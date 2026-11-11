#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],need[500005]={0};
int flag=-1;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    //for(int i=0;i<n;i++)cout <<a[i]<<' ';
    int i=1;
    for(;i<n;i++)
    {
        need[i]=need[i-1]+(a[i]-a[i-1])*i;
        if(need[i]>m)
        {
            flag=max(i,flag);
            break;
        }
    }
    int cnt=i;
    int cost=0;
    for(;i<n;i++)
    {
        while(need[i]>m&&cnt>0)
        {
            need[i]-=a[i]-a[cost];
            cnt--;
            cost++;

        }
        flag=max(flag,cnt);
        need[i]=need[i-1]+=(a[i]-a[i-1])*(i-cost);
    }
    //cout<<endl;
    //for(int i=0;i<flag+1;i++)cout <<need[i]<<' ';
    if(flag==-1)
    {
        cout << n;
        return 0;
    }
    cout <<flag;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
