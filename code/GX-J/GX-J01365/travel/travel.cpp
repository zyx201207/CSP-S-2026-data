#include<bits/stdc++.h>
using namespace std;
struct sum
{
    long long cx;
    string zw;
};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    sum a[1000];
    for(int i=0;i<2;i++)
        cin>>a[i].cx>>a[i].zw;
    for(int i=0;i<2;i++){
        if(a[i].cx=a[i+1].cx)
        {
            cout<<"1";
            int y=0,p=0,b=0,k=0,l=0;
            for(int j=0;j<3;i++){
                if(a[i].zw[j]==a[i+1].zw[j]&&i!=2) y++;
                if(j==2){
                    if(a[i].zw[j]>='A'&&a[i].zw[j]<='C') p=1;
                    else k=1;
                    if(a[i+1].zw[j]>='A'&&a[i+1].zw[j]<='C') b=1;
                    else l=1;
                }
            }
            if(y==2)
            {
                cout<<"1";
                if(p==b||k==l)
                {
                    cout<<"1";
                    int aj=a[i].zw[2]-97,ai=a[i+1].zw[2]-97;
                    if(aj-1==ai||aj+1==ai) cout<<"1";
                }
            }
        }
        else
        {
            cout<<"0000";
            break;
        }
        break;
    }
    return 0;
}
