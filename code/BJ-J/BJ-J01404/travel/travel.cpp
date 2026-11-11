#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
#define pb push_back
using namespace std;
int a1,a2,n1,n2;
string b1,b2;
char z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2){
        cout<<"0000"<<endl;
        return 0;
    }
    z1=b1[2],z2=b2[2];
    n1=(b1[0]-'0')*10+(b1[1]-'0'),n2=(b2[0]-'0')*10+(b2[1]-'0');
    if(n1!=n2){
        cout<<"1000"<<endl;
        return 0;
    }
    if((z1<'D')!=(z2<'D')){
        cout<<"1100"<<endl;
        return 0;
    }
    if(abs(z1-z2)!=1||(z1=='D'||z1=='F')){
        cout<<"1110"<<endl;
        return 0;
    }
    cout<<"1111"<<endl;
    return 0;
}
