#include<bits/stdc++.h>
using namespace std;
int a[10000],b[210000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,n;
    cin>>c>>n;
    while(n--){
        int m,d;
        cin>>m>>d;
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        if(m<=3){
            cout<<0;
            continue;
        }
        for(int i=2;i<=m;i++){
            b[i-1]=abs(a[i]-a[i-1]);
        }
        int num=b[1],ok=1,ans=0;
        for(int i=2;i<m;i++){
            if(b[i]==b[i]){
                ok++;
            }
        }
        if(ok==m-1){
            if(num>=d){
                cout<<0;
                continue;
            }
            else{
                for(int i=1;i<m;i++){
                    ans+=num;
                    if(ans>=d){
                        ans=i+1;
                        break;
                    }
                }
                if(ans>=4){
                    for(int i=4;i<=ans;i++){
                        ans+=i;
                    }

                }
                cout<<ans;
            }
        }
    }
    return 0;
}
