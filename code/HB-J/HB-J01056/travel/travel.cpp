#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool flag=0,flag1=0,flag2=0,flag3=0;
    if(c1!=c2){
        cout<<flag<<flag1<<flag2<<flag3;
        return 0;
    }
    else{
        if(s1[0]!=s2[0]||s1[1]!=s2[1]){
            cout<<1<<0<<0<<0;
            return 0;
        }
        else{
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F')){
                cout<<1<<1<<0<<0;
                return 0;
            }
            else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')){
                cout<<1<<1<<0<<0;
                return 0;
            }
            else{
                if(abs(s2[2]-s1[2])==1&&(s1[2]!='D'&&s2[2]!='C'||s1[2]!='C'&&s2[2]!='D')){
                    cout<<1<<1<<1<<1;
                    return 0;
                }
                else cout<<1<<1<<1<<0;
            }
        }
    }
    return 0;
}
