#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(0));
    int n,a,t;
    cin>>a>>t;
    while(t--){
        cout<<rand()%n-1<<endl;
    }
}
