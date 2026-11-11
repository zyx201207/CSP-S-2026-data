#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    srand(time(0));
    for(int i=1;i<=t;i++){
        cout<<rand()%2+1<<endl;
    }
}