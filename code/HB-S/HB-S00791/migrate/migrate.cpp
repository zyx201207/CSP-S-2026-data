#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0,flag=0,num=0;
        bool OK=true;
        int a[5000];
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=i;k<=j;k++){
                    flag=0;
                    for(int z=k+1;z<=j;z++){
                        if(a[z]-a[k]<=d)flag++;
                    }if(flag>2)OK=false;
                    else if(flag==2)num++;
                }
            }if(OK==true && num==1)ans++;
        }
        cout<<ans<<endl;
    }return 0;
}
/*

*/