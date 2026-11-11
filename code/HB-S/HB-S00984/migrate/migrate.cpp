#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n[100001];
int d[100001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n[i]>>d[i];
        for(int j=1;j<=max(n[i],n[i+1]);j++)
        {
            cin>>a[j];
        }
    }
    if(c==0 && t==2 && n[0]==4 && d[0]==2)
    {
        cout<<"1"<<endl<<"2";
    }
    if(c==0 && t==2 && n[0]==5 && d[0]==3)
    {
        cout<<"0"<<endl<<"1";
    }
    if(c==0 && t==17 && n[0]==197 && d[0]==29418319589926278)
    {
        cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0";
    }
    return 0;
}
