#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t1_n,t2_n;
    string seat1,seat2;
    cin>>t1_n>>seat1>>t2_n>>seat2;
    if(t1_n==t2_n){
        cout<<"1";
    }
    else cout<<"0";
    if(t1_n==t2_n&&seat1[1]==seat2[1]){
        cout<<"1";
    }
    else cout<<"0";
    if(t1_n==t2_n&&seat1[1]==seat2[1]&&((seat1[2]>='D'&&seat2[2]>='D')||(seat1[2]<='C'&&seat2[2]<='C'))){
        cout<<"1";
    }
    else cout<<"0";
    if(t1_n==t2_n&&seat1[1]==seat2[1]&&((seat1[2]>='D'&&seat2[2]>='D')||(seat1[2]<='C'&&seat2[2]<='C'))&&(seat1[2]+1==seat2[2]||seat1[2]-1==seat2[2])||((seat1[2]=='F'&&seat2[2]=='D')||(seat2[2]=='F'&&seat1[2]=='D'))){
        cout<<"1";
    }
    else cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
