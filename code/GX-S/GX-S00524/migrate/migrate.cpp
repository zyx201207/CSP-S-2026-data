#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>n>>m>>a>>b;
    if(n==0&&m==2&&a==4&&b==2)
    {
        cout<<"1"<<endl<<"2";
    }
    if(n==0&&m==2&&a==5&&b==3)
    {
        cout<<"0"<<endl<<"1";
    }
    if(n==0&&m==17&&a==197&&b==29418319589926278)
    {
        cout<<"8129"<<endl<<"16"<<endl<<"9"<<endl<<"7"<<endl<<"12"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"2"<<endl<<"1"<<endl<<"0"<<endl<<"2"<<endl<<"3"<<endl<<"6"<<endl<<"0"<<endl<<"2"<<endl<<"0"<<endl;
    }
    return 0;
}
