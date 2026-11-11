#include<bits/stdc++.h>
using namespace std;
char b[1000001];
int a[1000001];
int bmi=2147483641,bma=-1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","W",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        bma=max(bma,int(b[i]));
        bmi=min(bmi,int(b[i]));
    }
    if(bmi==bma){
        cout<<"0";
        return 0;
    }
    return 0;

}
