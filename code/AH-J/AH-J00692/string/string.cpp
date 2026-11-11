#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,b,ans,r,l;
    string m;
    cin>>n;
    while(n--){
        cin>>a;
        cin>>b;
        int i=a;
        while(i--){
            m=m+b;
    }
    int a=n/2;
    int l=0,r=sizeof(m)+1;
    while(n--){
        if(m[l]!=m[r]){
            ans++;
            r--;
            l++;
        }else{
            r--;
            l++;
        }
    }
    cout<<ans;
    return 0;
    }
}
