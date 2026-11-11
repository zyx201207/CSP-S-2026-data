#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string n1,m1;
    cin>>n;
    cin>>n1;
    cin>>m;
    cin>>m1;
    int hang1=0,hang2=0;
    char seat1,seat2;
    int j=10;
    for(int i=0;i<n1.size();i++)
    {
        if(n1[i]>='0'&&n1[i]<='9')
        {
            hang1+=int(n1[i]-48)*j;
            j/=10;
        }
        else
        {
            seat1=n1[i];
        }
    }
    j=10;
    for(int i=0;i<m1.size();i++)
    {
        if(m1[i]>='0'&&m1[i]<='9')
        {
            hang2+=int(m1[i]-48)*j;
            j/=10;
        }
        else
        {
            seat2=m1[i];
        }
    }
    if(m!=n)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        cout<<1;
        if(hang1!=hang2)
        {
            cout<<"000";
            return 0;
        }
        else
        {
            cout<<1;
            if(seat1=='A'&&seat2=='B'||seat1=='B'&&seat2=='A'||seat1=='A'&&seat2=='C'||seat1=='C'&&seat2=='A'||seat1=='B'&&seat2=='C'||seat1=='C'&&seat2=='B')
            {
                cout<<1;
                if(seat1=='A'&&seat2=='B'||seat1=='B'&&seat2=='A'||seat1=='B'&&seat2=='C'||seat1=='C'&&seat2=='B')
                cout<<1;
                else
                cout<<0;
            }
            else if(seat1=='D'&&seat2=='F'||seat1=='F'&&seat2=='D')
            {
                cout<<"11";
            }
            else
            {
                cout<<"00";
                return 0;
            }
        }
    }
}