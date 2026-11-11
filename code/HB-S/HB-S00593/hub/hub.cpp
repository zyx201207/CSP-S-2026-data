#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c>=13&&c<=14){
        while(t--){
            int n,k;
            cin>>n>>k;
            for(int i=1;i<n;i++){
                int x,y;
                cin>>x>>y;

            }
            int m=n/2;
            if(k==n) cout<<0<<'\n';
            else if(k>=m) cout<<1<<'\n';
            else{
                int a=m/2;
                int b=m-a;
                int c=k/2;
                int d=k-c;
                cout<<max((a-c+1)/2,(b-d+1)/2)+1<<'\n';
            }
        }
    }
    return 0;
}