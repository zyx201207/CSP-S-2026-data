#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,s=0;string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;s++;
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<1;s++;
            if((c[2]<='C'&&d[2]<='C')||(c[2]>'C'&&d[2]>'C')){
                cout<<1;s++;
                if(c[2]-d[2]==1||c[2]-d[2]==-1){
                    cout<<1;s++;
                }
            }
        }
    }
    for(int i=4;i>s;i--)cout<<0;
    return 0;
}
