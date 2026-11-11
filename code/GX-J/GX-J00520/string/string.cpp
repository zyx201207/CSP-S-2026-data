#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n, i, j, num[10000];
    char x[10000];
    cin>>n;
    for(i=1; i<=n; i++){
        cin>>num[i]>>x[i];
    }


    if(n==1)
        cout<<0;

    else if(n==2){
        if(num[1]==num[2])
        cout<<0;
        else{
            cout<<min(num[1],num[2]);
        }
    }

    return 0;
}
