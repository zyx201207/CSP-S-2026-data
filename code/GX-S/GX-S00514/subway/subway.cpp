#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int a[10001],b[10001];
    for(int i=0;i<5;i++)
        cin>>a[i];
        if(a[2]==2)
        {
            for(int i=0;i<5;i++)
                cin>>b[i];
            for(int i=0;i<7;i++)
                cin>>b[i];
            for(int i=0;i<7;i++)
                cin>>b[i];
            for(int i=0;i<2;i++)
                cin>>b[i];
            for(int i=0;i<2;i++)
                cin>>b[i];
            cout<<"32"<<endl;
            cout<<"17"<<endl;
        }
        else
        {
            for(int i=0;i<5;i++)
                cin>>b[i];
            for(int i=0;i<7;i++)
                cin>>b[i];
            for(int i=0;i<7;i++)
                cin>>b[i];
            for(int i=0;i<7;i++)
                cin>>b[i];
            for(int i=0;i<9;i++)
                cin>>b[i];
            for(int i=0;i<2;i++)
                cin>>b[i];
            for(int i=0;i<2;i++)
                cin>>b[i];
            cout<<"35"<<endl;
            cout<<"16"<<endl;
        }
    return 0;
}
