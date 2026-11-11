//贾启航 个人报名GZ-J00385
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string nn,mm;
    cin>>n>>nn>>m>>mm;

    if(n==m){
        cout<<1;
        if(nn==mm){
            cout<<1<<1<<1<<1;
        }
    }else
        cout<<0<<0<<0<<0;
    return 0;
}
