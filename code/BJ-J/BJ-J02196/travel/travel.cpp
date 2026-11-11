#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    cin>>n;
    string n1,m1;
    cin>>n1>>m>>m1;
    if(n!=m){
        cout<<"0000";
        return 0;
    }
    int p=n1[0]*10+n1[1],q=m1[0]*10+m1[1];
    if(p!=q){
        cout<<1000;
        return 0;
    }
    int p1=n1[2]-'A'+1;
    int q1=m1[2]-'A'+1;
    if((p1>=4&&q1<=3)||(p1<=3&&q1>=4)){
        cout<<1100;
        return 0;
    }
    if(p1<=3&&abs(q1-p1)>1){
        cout<<1110;
        return 0;
    }
    cout<<1111;
    return 0;
}
