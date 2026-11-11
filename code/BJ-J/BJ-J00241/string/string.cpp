#include<bits/stdc++.h>
using namespace std;

int a[10010];
char b[10010];
string d;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    bool c=true;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
        if(i>=1){
            if(b[i]!=b[i-1]){
                c=false;
            }
        }
        for(int j=0;j<a[i];j++){
            d+=b[i];
        }
    }
    if(c==true){
        cout<<0;
        return 0;
    }
    long long ans=0;
    for(int i=0;i<sum/2;i++){
        if(d[i]!=d[sum-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
