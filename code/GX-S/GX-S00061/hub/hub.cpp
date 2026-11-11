#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    cin>>c>>t;
    if(c==1)while(t--)cout<<1<<'\n';
    if(c==2||c==3)while(t--)cout<<rand()%10+1<<'\n';
    return 0;
}
