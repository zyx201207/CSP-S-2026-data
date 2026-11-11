#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000010],v[1000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
        }
        int m=n/2;
        if(k<=m){
            int mm;
            if(m%2==0) mm=m/2;
            else mm=m/2+1;
            k--;
            int right=mm+(k/2);
            cout<<m+1-right;
        }else{
            if(k<n-1) cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
