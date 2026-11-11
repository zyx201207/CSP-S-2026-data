#include<bits/stdc++.h>
using namespace std;
long long a[1000000],ans=0,sum=10000000000,us=0;
string s,o;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    char c[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        us+=a[i];
    }if(us%2==0){
        for(int j=1;j<=n;j++){
            ans=0;
            for(int i=1;i<=n;i++){
                if(s[i]!=s[j]){
                    ans+=a[i];
                }
            }if(ans<sum)sum=ans;
        }
    }else {
        for(int j=1;j<=n;j++){
            ans=0;
            for(int i=1;i<=n;i++){
                if(s[i]!=s[j]){
                    ans+=a[i];
                }
            }if(ans-1<sum&&ans!=0)sum=ans-1;
            if(ans==0)sum=ans;
        }
    }cout<<sum;
    return 0;
}
