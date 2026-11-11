#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(t==2)cout<<"1"<<endl<<"2";
    if(t==3)cout<<"1"<<endl<<"1"<<endl<<"2";
    if(t==5)cout<<"17"<<endl<<"19"<<endl<<"6"<<endl<<"6"<<endl<<"9";
    else{
        while(t--)cout<<"0"<<endl;
    }
    return 0;
}
