#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    bool b[4]={true,true,true,true};
    char ch[13];
    for(int i=0;i<10;i++){
        cin>>ch[i];
    }
    if(ch[0]==ch[5] && ch[1]==ch[6]){
        cout<<1;
    }else{
        cout<<0;
        b[0] = false;
    }
    if(b[0] && ch[2]==ch[7] && ch[3]==ch[8]){
        cout<<1;
    }else{
        cout<<0;
        b[1] = false;
    }
    if (b[1] && ((ch[4] == 'F' && ch[9] == 'D') || (ch[4] == 'D' && ch[9] == 'F') || (ch[4] == 'C' && ch[9] == 'A') || (ch[4] == 'A' && ch[9] == 'C') || (ch[4] == 'C' && ch[9] == 'B') || (ch[4] == 'B' && ch[9] == 'C') || (ch[4] == 'A' && ch[9] == 'B') || (ch[4] == 'B' && ch[9] == 'F')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
        b[2] = false;
    }
    if (b[2] && !((ch[4] == 'C' && ch[9] == 'A') || (ch[4] == 'A' && ch[9] == 'C')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
