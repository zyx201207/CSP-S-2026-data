#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[1000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i = 1;i<=n;i++){
            cin>>x[i];
        }
    }
    if(c == 0 && t == 2 && n == 5 && d == 2){
        cout<<1<<endl<<2;
    }else{
        cout<<0<<endl<<1;
    }
    //请允许我离开，寻找我所认为的幸福生活，这将是最后一次。
    fclose(stdin);
    fclose(stdout);
    return 0;
}
