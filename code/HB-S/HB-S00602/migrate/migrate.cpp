#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x[100005],c,t,n,d,ans=0;
    int sum=0;
    cin>>c>>t;
    for(int j=1;j<=t;j++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
    }
    for(int j=1;j<=t;j++){
        for(int i=1;i<=n;i++){
            if(x[i]-x[i-1]<=d){
                ans+=1;
            }
        }

        sum=(ans-1)/2;

        cout<<sum/2<<endl;
    }
    return 0;
}





