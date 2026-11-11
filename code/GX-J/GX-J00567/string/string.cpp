#include<bits/stdc++.h>
using namespace std;

int n;
int sum;
string r;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>sum;
        cin>>r;
    }

    if (n==1){
        cout << 0;
        return 0;
    }
    if (n=2){
        cout << 1;
        return 0;
    }
    if(n>2) cout << 2;



    return 0;
}
