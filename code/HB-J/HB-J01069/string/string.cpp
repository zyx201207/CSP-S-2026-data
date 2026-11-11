#include<bits/stdc++.h>
using namespace std;
int n,a,cnt;
string s,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b[i];
        if(b[i-1]!=b[i]){
            cnt++;
        }
    }
    cout<<cnt-1;
    return 0;
}
