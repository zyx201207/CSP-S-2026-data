#include>bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    for(int i=1;i<+n;i++){
        if(s=n+1){
            n++;
        }
    }
    cout<<n;
    return 0;
}
