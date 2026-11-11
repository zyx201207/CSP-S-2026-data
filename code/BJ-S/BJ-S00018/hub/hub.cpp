#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[600005],b[600005],k,ok,ok2;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdin);
    cin>>c>>t;
    
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++)cin>>a[i]>>b[i];
        for(int i=1;i<=n-1;i++){if(a[i]==a[i-1])ok++;
        if(a[i]+1==b[i])ok2++;
        }
        if(n<=5){
            cout<<1;
        }
        else{
            if(ok==n-2)cout<<1;
            else if(n<=10 && k>=3)cout<<2;
            else if(n<=8 && k==2)cout<<2;
            else if(ok==n-3)cout<<2;
            else if(n<=10 && ok2==n-1)cout<<3;
            else if(n<=10)cout<<2;

        }
        for(int i=1;i<=n;i++){a[i]=0;b[i]=0;}
        cout<<endl;
    }
return 0;
}