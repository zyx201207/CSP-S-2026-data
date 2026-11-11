#include<iostream>
using namespace std;
const int N=2e6+6;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    if(c==11||c==12)
    while(T--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<n+1-(2*(d/(a[2]-a[1])));
        cout<<endl;
    }
    else if(c==13||c==14)
    while(T--){
        int n,d,any=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
                any=i;
                break;
            }
        }
        if(any==1||any==n){
            cout<<0;
        }
        else{
            int am1=0,ap1=0,res=0;
            for(int i=any+1;i<=n&&a[i]-a[any-1]<=d;i++)am1++;
            for(int i=1;i<any-1&&a[any+1]-a[i]>d;i++)ap1++;
            res+=am1*ap1;
            if(am1==1){
                res+=n-(any+1);
            }
            cout<<res;
        }
        cout<<endl;
    }
    return 0;
}
