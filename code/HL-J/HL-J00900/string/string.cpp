#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[5000005],r[5000005];
    int n;
    int a,ans=0;
    char x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>x;
        for(int j=0;j<a;j++){
            s[j]=x;
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=n/2;j>0;j--){
            r[j]=s[i];
        }
        break;
    }
    for(int i=0;i<n/2;i++){
        if(s[i]==r[i])  continue;
        else{
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
