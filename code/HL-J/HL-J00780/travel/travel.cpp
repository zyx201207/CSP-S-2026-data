#include<bits/stdc++.h>
using namespace std;
string r2,x2;
long long r1,x1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    long long sum1=0,sum2=0;
    long long cnt1=0,cnt2=0;
    char ans1,ans2;
    for(int i=0;i<r2.size();i++)
    {
        if(i==0)
        {
            sum1+=r2[i]*10;
        }
        if(i==1)
        {
            sum1+=r2[i];
        }
        if(i==2)
        {
            cnt1=int(r2[i]);
            ans1=r2[i];
        }
    }
    for(int i=0;i<x2.size();i++)
    {
        if(i==0)
        {
            sum2+=x2[i]*10;
        }
        if(i==1)
        {
            sum2+=x2[i];
        }
        if(i==2)
        {
            cnt2=int(x2[i]);
            ans2=x2[i];
        }
    }
    if(abs(sum1-sum2)==0)
    {
        cout<<1;
        if(abs(cnt1-cnt2)==1)
        {
            if(ans1=='C'&&ans2=='D'||ans1=='D'&&ans2=='C')
            {
                cout<<"00";
                return 0;
            }
            cout<<11;
            return 0;
        }
        if(abs(cnt1-cnt2)==2&&(ans1=='D'&&ans2=='F'||ans1=='F'&&ans2=='D'))
        {
            cout<<11;
            return 0;
        }
        else
        {
            if(abs(cnt1-cnt2)==2&&(ans1=='A'&&ans2=='C'||ans1=='C'&&ans2=='A'))
            {
                cout<<10;
            }
            else
            {
                cout<<"00";
            }
            return 0;
        }

    }
    else
    {
        cout<<"000";
        return 0;
    }

    return 0;
}
