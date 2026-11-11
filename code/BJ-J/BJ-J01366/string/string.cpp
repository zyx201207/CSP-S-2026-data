#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200100]={};
    char c[200100]={};
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<=n;i++){
        while(a[i]>a[j]){
            a[i]-=a[j];
            if(c[i]!=c[j]){
                ans+=a[j];
            }
            a[j]=0;
            j--;
        }
        if(a[i]){
            a[j]-=a[i];
            if(c[i]!=c[j]) ans+=a[i];
            a[i]=0;
        }
    }

    cout<<ans;
    return 0;
}
