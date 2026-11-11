#include<bits/stdc++.h>
using namespace std;
long long a[500010];
priority_queue<long long,vector<long long>,greater<long long>> cha[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    //long long sum=0;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        //sum+=a[i];
        //cha[i]=a[i]-a[i-1];
    }
    long long mx=0;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            if(a[i]>=a[j])
                cha[i].push(a[i]-a[j]);
            else
                cha[j].push(a[j]-a[i]);
            //cha[i].push(abs(a[i]-a[j]));
            //cha[j].push(abs(a[i]-a[j]));
        }
        long long sum=0;
        long long cnt=1;
        while(!cha[i].empty()&&sum+cha[i].top()<=m)
        {
            cnt++;
            sum+=cha[i].top();
            //cout<<"cha "<<cha[i].top()<<endl;
            cha[i].pop();
        }
        mx=max(mx,cnt);
    }
    cout<<mx<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
