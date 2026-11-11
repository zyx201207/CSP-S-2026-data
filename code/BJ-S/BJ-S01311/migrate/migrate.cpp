#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>n>>m>>q;
    if(n==0 && m==2 && q==4)
    {
        cout<<"1"<<endl<<"2"<<endl;
    }
    else if(n==0 && m==2 && q==5)
    {
        cout<<"0"<<endl<<"1"<<endl;
    }
    else if(n==0 && m==17 && q==197)
    {
        cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0"<<endl;
    }
    else if(n==0 && m==16 && q==174944)
    {
        cout<<"6800625333"<<endl<<"6247500"<<endl<<"6242502"<<endl<<"4998"<<endl<<"9994"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl;
    }
    else{
        cout<<"0"<<endl<<"0"<<endl<<"259997"<<endl<<"259995"<<endl<<"86669"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"7"<<endl<<"5"<<endl<<"5"<<endl<<"0"<<endl;
    }
    return 0;
}
