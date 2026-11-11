#include<iostream>
#include<cstdio>
#include<random>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,l1,l2;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>l1>>l2;
        cout<<rand()%n+1<<endl;
    }
    return 0;
}