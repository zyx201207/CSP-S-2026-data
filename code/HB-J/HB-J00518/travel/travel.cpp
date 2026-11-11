#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int n,m;
int num,nem;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>n;
    cin>>a;
    cin>>m;
    cin>>b;
    if(n==m){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(a[0]==b[0] && a[1]==b[1]){
        cout<<1;
        if(a[2]<='C'&&b[2]<='C'||a[2]>='D'&&b[2]>='D'){
            cout<<1;
        }
        else{
            cout<<0;
        }
        if(a[2]-b[2]==1 || b[2]-a[2]==1){

            if(a[2]=='C'&& b[2]=='D'|| a[2]=='D'&&b[2]=='C'){
                cout<<0;
            }
            else{
                cout<<1;

            }
        }
    }
    else{
        cout<<0<<0<<0;
    }
        return 0;
}
