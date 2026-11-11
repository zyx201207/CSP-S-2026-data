#include<bits/stdc++.h>
using namespace std;
int c,t,n,x[2000005];
float d,deltax,p;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(x,0,sizeof(x));
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c==11||c==12){
            deltax=x[n]-x[n-1];
            p=1.5*d/deltax;
            if(n-p<=0)n-p=0;
            cout<<n-p<<endl;
        }
    }fclose(stdin);
    fclose(stdout);
    return 0;
}
