#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n;
    int m;
    int k=0;
    cin>>n;
    cin>>m;
    while(n>=1){
        if(n%2==0)
            k++;
            n /= 2;
    }
    cout<<k;



    return 0;
}
