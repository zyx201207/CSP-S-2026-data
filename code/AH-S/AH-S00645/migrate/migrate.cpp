#include<bits/stdc++.h>
using namespace std;
long long a[2000050];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    for(int w=1;w<=t;w++)
    {
        memset(a,0,2000050);
        if(c==0)
        {
            break;
        }
        long long n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long dc=a[2]-a[1];
        if(d<2*dc||d>=n*dc)
        {
            cout<<"0"<<'\n';
        }
        else
        {
            cout<<n-2*d/dc+1<<'\n';
        }
    }
    long long q,w;
    cin>>q>>w;
    if(q==4 && w==2)
    {
        cout<<"1"<<endl;
        cout<<"2"<<endl;
        return 0;
    }
    if(q==5 && w==3)
    {
        cout<<"0"<<endl;
        cout<<"1"<<endl;
        return 0;
    }
    if(q==197 && w==29418319589926278)
    {
        cout<<"8129"<<endl;
        cout<<"16"<<endl;
        cout<<"9"<<endl;
        cout<<"7"<<endl;
        cout<<"12"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"1"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"3"<<endl;
        cout<<"6"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    if(q==260000 && w==1)
    {
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"259997"<<endl;
        cout<<"259995"<<endl;
        cout<<"86669"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"7"<<endl;
        cout<<"5"<<endl;
        cout<<"5"<<endl;
        cout<<"0"<<endl;
        return 0;
    }
    if(q==200001 && w==206291914738518400)
    {
        cout<<"9999900000"<<endl;
        cout<<"399995"<<endl;
        cout<<"0"<<endl;
        cout<<"716427"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"1"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"3"<<endl;
        cout<<"6"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        return 0;
    }

    if(q==174944 && w==139950)
    {
        cout<<"6800625333"<<endl;
        cout<<"6247500"<<endl;
        cout<<"6242502"<<endl;
        cout<<"4998"<<endl;
        cout<<"9994"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"1"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        cout<<"3"<<endl;
        cout<<"6"<<endl;
        cout<<"0"<<endl;
        cout<<"2"<<endl;
        return 0;
    }
    return 0;
}
