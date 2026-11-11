#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[1000];
    int m=1;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b=a[2];
    for (int i=1;i<=n;i++){
        if(i%2==0){
            if (a[i]==b){
                m=1;
            }
            else{
                cout<<3000000000;
            }
        }
    }
    if (m==1) cout<<0;
    return 0;
}
