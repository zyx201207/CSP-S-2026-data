#include <bits/stdc++.h>

using namespace std;
string a,b,c,d;
char ansb,ans1,ans2;
int main()
{
    freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int r=(b[0]-'0')*10+(b[1]-'0');
    int x=(d[0]-'0')*10+(d[1]-'0');
    //cout<<b[2]<<d[2]<<r<<x;;
    if(a==c){
        ans1='1';
        cout<<ans1;
        if(r==x){
            ans2='1';
            cout<<ans2;
            if(b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C'){
                ansb='1';
                cout<<ansb;
            }else if(b[2]>='D' && b[2]<='E' && d[2]>='D' && d[2]<='E'){
                ansb='1';
                cout<<ansb;
            }else{cout<<'0';}
            if((b[2]+1==d[2] || b[2]-1==d[2])&&ansb=='1'){
                char ans='1';
                cout<<ans;
            }else cout<<'0';
        }else{cout<<'0'<<'0'<<'0';}


    }else{cout<<'0'<<'0'<<'0'<<'0';}

    return 0;
}