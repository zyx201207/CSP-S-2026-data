#include<bits/stdc++.h>
using namespace std;
int in1,n,ans;
char in2;
string a;
int main(){
    cin>>n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=0;i<n;i++){
        cin>>in1>>in2;
        a+=(in1*in2);
    }for(int i=0,j=n-i;i<n;i++,j--){
        if(a[i]!=a[j]){
            ans++;
        }
    }cout<<ans;
    return 0;
}