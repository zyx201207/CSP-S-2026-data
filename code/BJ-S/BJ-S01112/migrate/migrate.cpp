#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[20000005];
int f(int a){
    int cnt=0;
    for(int i=1;i<=d;i++){
        if((a-d)<=d){
            cnt++;
        }else{
            cnt+=f(a-d);
        }
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        int cnt=0;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        for(int a=1;a<=n;a++){
            for(int b=3;b<=n;b++){
                if(f(b-a)==2){
                    cnt++;
                }
            }

        }
        cout<<cnt;

    }

    return 0;
}


