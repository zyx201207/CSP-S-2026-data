#include <bits/stdc++.h>

using namespace std;

int a,b,c,d,c1,c2;
string s;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s;
    for(int i=0;i<=1;i++)b=b*10+s[i]-'0';
    c1=s[2]-'A'+1;
    cin>>c>>s;
    for(int i=0;i<=1;i++)d=d*10+s[i]-'0';
    c2=s[2]-'A'+1;
    if(a==c){
        if(b==d){
            if((c1>=1&&c2>=1&&c1<=3&&c2<=3)){
                if(abs(c2-c1)==1){
                    cout<<"1111";
                }
                else cout<<"1110";
            }
            else if(c1>=4&&c2>=4&&c1<=5&&c2<=5){
                cout<<"1111";
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
