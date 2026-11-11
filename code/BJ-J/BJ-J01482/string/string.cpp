#include <iostream>
using namespace std;
char a[999999999];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int d=1;
    int f=1;
    for(int i=1;i<=n;i++){
        int b;
        char c;
        cin>>b>>c;
        f+=b;
        for(int j=1;j<=b;j++){
            a[d]=c;
            d++;
        }
    }
    int num=0;
    for(int i=1;i<=f/2;i++){
        if(a[i]!=a[f-i]){
            num++;
        }
    }
    cout<<num;
    return 0;
}
