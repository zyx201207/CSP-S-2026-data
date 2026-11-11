#include<bits/stdc++.h>
using namespace std;
char s[100000001];
char c[100000001];
int n,l,a[100000001],ans=0,k=0;
int main(){
    cin>>n;
    l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++){
            s[k]=c[i];
            k++;
        }
    }
    if(l==1){
        cout<<0<<endl;
        return 0;
    }
    if(l%2==0){
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1]){
                ans++;
            }
        }
    }
    else{
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-i-1]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
