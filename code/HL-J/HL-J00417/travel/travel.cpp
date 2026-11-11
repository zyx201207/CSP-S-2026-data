#include <bits/stdc++.h>
using namespace std;
struct tick{
    string name,seat;
}a[10010];
bool c[1001][5]={};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
        cin>>a[i].name>>a[i].seat;
    }
    string c[1010]={};
    for(int i=1;i<=2;i++){
            string hj[1001]={};
            hj[i]=a[i].seat;
        if(i==2){
            if(a[i].name==a[i-1].name)c[0]='1';
            else c[0]='0',c[1]='0',c[2]='0',c[3]='0',break;
        }
    }
    for(int i=0;i<4;i++){
        cout<<c[i];
    }
    return 0;
}
