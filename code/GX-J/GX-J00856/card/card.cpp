#include <bits/stdc++.h>
using namespace std;
int main(){
    //fireopen("card.in"and"r",stdin)
    //fireopen("card.out"and"w",stdout)
    int n,m;
    cin >> n>>m;
    int num[n];
    for (int i=0; i<n; i++){
        cin >>num[i];
    }
    int b=0;
    for (int i=0; i<n; i++){
        if(num[i]==n){
            b++;
        }
    }
    cout<<m<<" "<<b<<" "<<n;
    return 0;
}
