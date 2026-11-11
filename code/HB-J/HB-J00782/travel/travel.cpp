#include<bits/stdc++.h>
using namespace std;
struct ticket{
    string car,row;
    char seat;
}a,b;
bool ans1,ans2,ans3,ans4;
bool pdr(char a,char b){
    if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))return true;
    if((a=='D'||a=='F')&&(b=='D'||b=='F'))return true;
    return false;
}
bool pdne(char a,char b){
    if((a=='D'||a=='E')&&(b=='D'||b=='F'))return true;
    if((a=='A'||a=='B')&&(b=='A'||b=='B'))return true;
    if((a=='B'||a=='C')&&(b=='B'||b=='C'))return true;
    return false;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a.car>>a.row;
    cin>>b.car>>b.row;
    a.seat=a.row[2];
    b.seat=b.row[2];
    if(a.car!=b.car){
        cout<<ans1<<ans2<<ans3<<ans4;
        return 0;
    }
    ans1=1;
    for(int i=0;i<=1;i++){
        if(a.row[i]!=b.row[i]){
            cout<<ans1<<ans2<<ans3<<ans4;
            return 0;
        }
    }
    ans2=1;
    if(pdr(a.seat,b.seat)){
        ans3=1;
    }
    else {
        cout<<ans1<<ans2<<ans3<<ans4;
        return 0;
    }
    if(pdne(a.seat,b.seat))ans4=1;
    else{
        cout<<ans1<<ans2<<ans3<<ans4;
        return 0;
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}