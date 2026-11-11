#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S;
    cin>>S;
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<=n;i++){
            int a[n];
        int i1=i%10;
        int i2=i%10/10;
        int i3=i/100;
        if(i=a[n]){
            cout<<S;
        }else{
            ans++;
            cout<<ans;
        }
    }
    return 0;
}
