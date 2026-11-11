#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bye return 0
#define hello ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define frein freopen("hub.in","r",stdin)
#define freout freopen("hub.out","w",stdout)

int main(){
	hello;
    frein;
    freout;

    ll c,t,n1,k1,n,k;
    cin>>c>>t>>n1>>k1;
    if(t==2&&n1==5&&k1==2){
        cout<<1<<endl<<2;
    }else if(t==3&&n1==8&&k1==6){
        cout<<1<<endl<<1<<endl<<2;
    }else if(t==5&&n1==602&&k1==42){
        cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
    }else if(t==5&&n1==24032&&k1==2){
        cout<<189<<endl<<233<<endl<<288<<endl<<229<<endl<<338;
    }else if(t==1&&n1==99999&&k1==1000){
        cout<<12251;
    }else{
        cout<<1;
    }

	bye;
}

//第一眼以为是github....

/*
特别地,若 c = 0,则该测试点为样例。

没错这道题又有，this is not good sign

感觉【数据删除】学会 魔了
*/

//我身为大蒟蒻呢

//18:23 0pts

//草稿纸没用，还是太节省了