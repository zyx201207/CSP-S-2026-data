#include <bits/stdc++.h>
using namespace std;
string v;
int a[4]={0,0,0,0};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<4;i++){
        cin>>v[i];
    }
    if(v[0]==v[2]){
        a[0]=1;
        if(v[1]%10==v[3]%10){
            a[1]=1;
            if(V[1]%10=='C'||V[1]%10=='D'){
                a[2]=1;
            }
        }
        if(v[1]==v[3]+1||v[1]==v[3]-1){
            a[3]=1;
        }
    }
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
