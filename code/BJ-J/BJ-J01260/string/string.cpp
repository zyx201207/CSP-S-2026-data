#include<bits/stdc++.h>
using namespace std;
int a[100005];
char b[100005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long ans=0;
    for(int i=1,j=n;i<j;){
        if(b[i]==b[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }else{
                i++;
                j--;
            }
        }else{
            if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }else if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }else{
                ans+=a[i];
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
