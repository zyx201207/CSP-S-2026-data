#include<bits/stdc++.h>
using namespace std;
char ch1,ch2;
int seat_1,seat_2,train_1,train_2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>train_1>>seat_1>>ch1>>train_2>>seat_2>>ch2;
    if(train_1==train_2)
    {
        cout<<1;
        if(seat_1==seat_2)
        {
            cout<<1;
            if(ch1<='C'&&ch2<='C'||ch1>='D'&&ch2>='D')
            {
                cout<<1;
                if(ch1=='A'&&ch2=='B'||ch1=='B'&&ch2=='A'||
                   ch1=='B'&&ch2=='C'||ch1=='C'&&ch2=='B'||
                   ch1=='D'&&ch2=='F'||ch1=='F'&&ch2=='D')
                    cout<<1;
                else
                    cout<<0;
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}