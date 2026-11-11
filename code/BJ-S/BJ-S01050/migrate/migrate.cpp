#include<bits/stdc++.h>
using namespace std;

int n,d;
int iland[100010];
int lin[10010][10010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,q;
    cin>>c>>q;
    while(q--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>iland[i];
        }
        bool ff=1;
        for(int i=1;i<=n;i++){
            if(iland[i]-iland[1]>d||iland[n]-iland[i]>d){
                break;
                ff=0;
            }
        }
        if(ff==1){
            cout<<0<<endl;
            return 0;
        }
        int ch=iland[2]-iland[1],f=1;
        for(int i=3;i<=n;i++){
            if(iland[i]-iland[i-1]!=ch){
                f=0;break;
            }
        }
        if(f==1){
            if(n%2==0){
                if(n==2){
                    cout<<0<<endl;
                    return 0;
                }
                if(d<2*ch)cout<<0<<endl;
                else if(d>=2*ch){
                    if(n==4)cout<<0<<endl;
                    else cout<<0<<endl;
                }
                else {
                    cout<<2<<endl;
                }
            }
            else{
                if(d<2*ch)cout<<0<<endl;
                else if(2*ch<=d&&(n-1)*ch>=d)cout<<2<<endl;
                else cout<<0<<endl;
            }
            return 0;
        }
        cout<<0<<endl;
    }
    return 0;
}
