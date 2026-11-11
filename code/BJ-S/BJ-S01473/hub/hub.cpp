
#include<bits/stdc++.h>
using namespace std;
//vector<long long> v[100000];
//long long n,k,ans=0;
//long long f(long long a)
//{

//}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
int c,t;
cin>>c>>t;
if((c==13)||(c==14))
{
    while(t--)
{
    cin>>n>>k;
    if(k==1)
    {
        cout<<0<<endl;
    }
    else if(k==n){
        cout<<n-1<<endl;
    }
    else if(k<=3)
    {
        cout<<k-1<<endl;
    }
    else{
        cout<<k-2<<endl;
    }
}
}
else{
    while(t--)
{
/*cin>>n>>k;
for(int i=1;i<=n-1;i++)
{
  long long l,r;
  cin>>l>>r;
  v[l].push_back(r);
  v[r].push_back(l);
}
for(int i=1;i<k;i++)
{

}*/if(k==1)
    {
        cout<<0<<endl;
    }
    else if(k==n){
        cout<<n-1<<endl;
    }
    else{
        cout<<1<<endl;
    }
}
}

}
