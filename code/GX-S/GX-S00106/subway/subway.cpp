#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>e>>a>>b>>c>>d;
    if(a%2==0&&d==2){
        cout<<c/2+b+d+c/2+b+d-a<<endl<<c/2+b+d;
    }
    else if(a%2!=0&&d==2){
        cout<<c/2+b+d+c/2+b+d-a<<endl<<c/2+b+d-a;
    }else{
        for(int i=1;i<=e;i++){
            cout<<i*(c/2+b+d)+c/2+b+d-a<<endl;
        }
    }
    return 0;
}
