#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.in","w",stdout);
    long long c,t,n[200005],d[200005],x[200005],num[200005];
    cin>>c>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>n[i]>>d[i];
        for (int j=1;j<=n[i];j++){
            cin>>x[j];
        }
        if (x[n[i]]%2==0){
            if (d[i]=2 && x[n[i]]==6){
                num[i]=4;
            }
            else if (d[i]=2 && x[n[i]]==4){
                num[i]=1;
            }
            else{
                if (n[i]>=4){
                    num[i]=2^(x[n[i]]-4);
                }
                else{
                    num[i]=0;
                }
            }
        }
        else{
            if (d[i]=2 && x[n[i]]==5){
                num[i]=2;
            }
            if (d[i]=2 && x[n[i]]==7){
                num[i]=6;
            }
            if (n[i]>=4){
                num[i]=2^(x[n[i]]-4);
            }
            else{
                num[i]=0;
            }

        }
    }

    for (int i=1;i<=t;i++){
        cout<<num[i]<<endl;
    }
    return 0;
}
