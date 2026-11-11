#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long b[1000010];
string c[1000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>b[i]>>c[i];
    }
    int j=1,k=n;
    while(j!=k){
        if(c[j]==c[k]){
            if(b[j]>b[k]){
                b[j]-=b[k];
                k--;
            }else if(b[j]<b[k]){
                b[k]-=b[j];
                j++;
            }else if(b[j]==b[k]){
                j++;
                k--;
            }
        }else{
            if(b[j]>b[k]){
                ans+=b[k];
                b[j]-=b[k];
                k--;
            }else if(b[j]<b[k]){
                ans+=b[j];
                b[k]-=b[j];
                j++;
            }else if(b[j]==b[k]){
                ans+=b[k];
                j++;
                k--;
            }
        }
    }
    cout<<ans;
    return 0;
}
