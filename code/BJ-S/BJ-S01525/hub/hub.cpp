#include<iostream>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        int m=(n-1)/2;
        for(int i=1;i<=n;i++){
            int a,b;
            cin>>a>>b;
        }
        if(k==n)cout<<0;
        else if(k>m)cout<<1;
        else{
            int three=(m-k)/3;
            int dif=m-k-(3*three);
            if(dif==0||dif==1){
                cout<<three+1;
            }
            else{
                cout<<three+2;
            }
        }
        cout<<endl;
    }
    return 0;
}
