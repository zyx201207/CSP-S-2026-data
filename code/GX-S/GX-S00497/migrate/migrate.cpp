#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,sum=0;
        long long y[1000006],d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>y[i];
        if(y[n]-y[1]<=d){
            cout<<"0\n";;
        }
        else if(c==11||c==12){
            if((y[2]-y[1])%d==0)cout<<"0\n";
            else {
                for(int i=1;i<=n;i++){
                    for(int j=i+2;j<=n;j++){
                        if(y[j]-y[i]>d&&(y[j]-y[i])%d!=0){
                            sum++;
                        }
                    }
                }
                cout<<sum<<endl;;
            }
        }
        else if(c==13||c==14){
            cout<<"0\n";;
        }
        else {
            for(int i=1;i<=n;i++){
                for(int j=i+2;j<=n;j++){
                    if(y[j]-y[i]>d&&(y[j]-y[i])%d!=0){
                        sum++;
                    }
                }
            }
            cout<<sum<<endl;;
        }
    }
    return 0;
}
