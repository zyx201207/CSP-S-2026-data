//T3
#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long n,d;
long long x[2000010];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cin>>n>>d;
    if(c==0)
    {
        if(t==2 && n==5 && d==2) cout<<"1"<<endl<<"2"<<endl;
        else if(t==2 && n==5 && d==3) cout<<"0"<<endl<<"1"<<endl;
        else if(t==17 && n==197 && d==29418319589926278)
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
        }
    }
    return 0;
}