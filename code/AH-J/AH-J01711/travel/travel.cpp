#include<bits/stdc++.h>
using namespace std;
char a[3],b[3];
int main()
{
	
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,c2;
    string s1,s2;
    cin>>c1;
    for(int i=1;i<=3;i++) cin>>a[i];
    cin>>c2;
    for(int i=1;i<=3;i++) cin>>b[i];
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    if(a[1]==b[1] && a[2]==b[2]) cout<<'1';
    else{
        cout<<"000";
        return 0;
    }
    if((a[3]<='C' && b[3]<='C') || (a[3]>'C' && b[3]>'C')) cout<<'1';
    else {
        cout<<"00";
        return 0;
    }
    if((a[3]+1==b[3] || b[3]+1==a[3])||(a[3]=='D' && b[3]=='F') || (a[3]=='F' && b[3]=='D')) cout<<'1';
    else cout<<'0';
    return 0;
}
