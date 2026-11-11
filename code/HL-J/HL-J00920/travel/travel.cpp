#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a_1,a_2,b_1,b_2;
    cin>>a_1>>a_2>>b_1>>b_2;
    if(a_1==b_1) cout<<1;
    else cout<<0;
    if(a_2[0]==b_2[0]&&a_2[1]==b_2[1]) cout<<1;
    else cout<<0;
    if(a_2[2]<='C'&&b_2[2]<='C'){
        cout<<1;
        if((a_2[2]=='A'&&b_2[2]=='B')||(a_2[2]=='B'&&b_2[2]=='A')||(a_2[2]=='B'&&b_2[2]=='C')||(a_2[2]=='C'&&b_2[2]=='B')) cout<<1;
        else cout<<0;
    }
    else if(a_2[2]>='D'&&b_2[2]>='D'){
        cout<<1;
        if((a_2[2]=='D'&&b_2[2]=='F')||(a_2[2]=='F'&&b_2[2]=='D')) cout<<1;
        else cout<<0;
    }
    else cout<<0<<0;
    return(0);

    fclose(stdin);
    fclose(stdout);
}
