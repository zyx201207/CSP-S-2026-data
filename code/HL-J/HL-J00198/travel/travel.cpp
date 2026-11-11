#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char c=c1[0],s=c2[0],n=c1[1],m=c2[1];
    if(c==s&&n==m){
        cout<<1;
        char a=s1[0],b=s2[0],c=s1[1],d=s2[1],x=s1[2],y=s2[2];
        if(a==b&&c==d){
            cout<<1;
            if(x=='A'&&y=='B'||x=='A'&&y=='C'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='A'||x=='C'&&y=='B'||x=='F'&&y=='D'||x=='D'&&y=='F'){
                cout<<1;
                if(x=='A'&&y=='B'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B'||x=='F'&&y=='D'||x=='D'&&y=='F'){
                    cout<<1;
                }
                else cout<<0;
            }
            else{
                cout<<"00";
            }

        }
        else{
            cout<<"000";
            return 0;
        }

    }
    else cout<<"0000";
    return 0;
}



