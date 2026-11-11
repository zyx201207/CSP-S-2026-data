#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string str="";
    unsigned long long len=0,midlen,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
        for(int j=1;j<=a[i];j++){
            str+=c[i];
        }
    }
    if(len%2==1){
        midlen=len/2+1;
        for(int i=0;i<midlen-1;i++){
            if(str[i]!=str[len-1-i])ans++;
        }
    }
    else{
        midlen=len/2;
        for(int i=0;i<midlen;i++){
            if(str[i]!=str[len-1-i])ans++;
        }
    }
    cout<<ans;
    return 0;
}
