#include <bits/stdc++.h>
using namespace std;
char po[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,d=0;
    cin>>a;
    for(int i=0;i<a;i++){
        int num;
        cin>>num;
        char l;
        cin>>l;
        for(int j=0;j<num;j++){
            po[d]=l;
            d++;
        }
    }

    int c=0;
    for(int i=0;i<d/2;i++){
        if(po[i]!=po[d-i-1]){
            c++;
        }
    }

    cout<<c;
    return 0;
}
