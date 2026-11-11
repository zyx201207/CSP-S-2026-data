#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;

int main(void)
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        bool flag=true;
        for(int i=0;i<=1;i++){
            if(s1[i]!=s2[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<1;
            int t1,t2;
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') t1=1;
            else t1=2;
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') t2=1;
            else t2=2;
            if(t2==t1){
                cout<<1;
                if(int(s1[2])+1==int(s2[2])||int(s2[2])+1==int(s1[2])) cout<<1<<endl;
                else if(s1[2]=='D'&&s2[2]=='F') cout<<1<<endl;
                else if(s1[2]=='F'&&s2[2]=='D') cout<<1<<endl;
                else cout<<0<<endl;
            }
            else cout<<"00"<<endl;
        }
        else cout<<"000"<<endl;
    }
    else cout<<"0000"<<endl;

    return 0;
}
