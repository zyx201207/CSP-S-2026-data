#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,t,T,tim[5000001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++){
        cin>>tim[i];
    }for(int i=1,num;i<=n;i++){
        cin>>num;
        int a[num];
        for(int i=0;i<num;i++){
            cin>>a[i]>>T;
        }
    }while(t--){
        int p,q;
        cin>>p>>q;
        cout<<abs(n/2)*T+tim[p]+tim[q]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
