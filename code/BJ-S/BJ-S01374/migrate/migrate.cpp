#include<iostream>
using namespace std;
int c,t,n,d,x[100010],dist[10010][10010];
int main(){
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        int D=x[2]-x[1];
        int num=d/D;
        if(num==1)break;
        if(num%2==0)ans=n*(n-2)/4;
        else ans=(n-3)(n-1)/4;
        cout<<ans<<"\n";
    }
    return 0;
}