#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[2000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,j=1,k=2,flag=1,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }else if(n==2){
        if(b[1]==b[2]){
            cout<<0<<endl;
            return 0;
        }else{
            if(a[1]>a[2]){
                cout<<a[2]<<endl;;
                return 0;
            }else if(a[1]<=a[2]){
                cout<<a[1]<<endl;
                return 0;
            }
        }
    }else{
        for(int i=1;i<n;i++){
            if(b[i]!=b[i+1]){
                flag=0;
            }
        }
        if(flag==1){
            cout<<0<<endl;
            return 0;
        }
        if(n%2==0){
            for(int i=n/2+1;i<=n;i++){
                if(b[i]!=b[i-j]){
                    ans++;
                }
                j+=2;
            }
        }else{
            for(int i=n/2+2;i<=n;i++){
                if(b[i]!=b[i-k]){
                    ans++;
                }
                k+=2;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    return 0;
}
