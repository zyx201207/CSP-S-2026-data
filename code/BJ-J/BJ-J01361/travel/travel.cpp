#include<iostream>
using namespace std;
string s1,s2,c1,c2;
int sum[8]={1,1,1,2,2};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    bool flag=true;
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag=false;
            break;
        }
    }
    if(!flag)
    {
        cout<<"1000"<<endl;
        return 0;
    }
    if(sum[s1[2]-'A']!=sum[s2[2]-'A'])
    {
        cout<<"1100"<<endl;
        return 0;
    }
    int x=max(int(s1[2]-'A'),int(s2[2]-'A'));
    int y=min(int(s1[2]-'A'),int(s2[2]-'A'));
    if((y+1)!=x)
    {
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
}