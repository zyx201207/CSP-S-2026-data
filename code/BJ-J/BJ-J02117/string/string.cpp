#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int b=0;
    for(int i=1;i<=n;i++){
        int s;
        char t;
        cin>>s;
        cin>>t;
        for(int i=1;i<=s;i++){
            a[b]=t;
            b++;
        }
    }
    int ans=0;
    int p;
    if(b%2==0){
        p=b/2-1;
        for(int i=0;i<=p;i++){
            if(a[i]!=a[b-1-i]){
                ans++;
            }
        }
    }else{
        p=b/2;
        for(int i=0;i<=p;i++){
            if(a[i]!=a[b-1-i]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
