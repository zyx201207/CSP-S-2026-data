#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[maxn];
    char c[maxn];
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    long long ans=0;
    bool is=1;
    int i=0;
    int j=n-1;
    while(is){
        if(abs(i-j)==1)is=0;
        if(c[i]!=c[j]){
            if(a[i]<a[j]){
                ans+=a[i];
                a[j]-=a[i];
                i+=1;
            }else if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j-=1;
            }if(a[i]==a[j]){
                ans+=a[i];
                i+=1,j-=1;
            }
        }else{
            if(a[i]<a[j]){
                a[j]-=a[i];
                i+=1;
            }else if(a[i]>a[j]){
                a[i]-=a[j];
                j-=1;
            }else{
                i+=1,j-=1;
            }
        }
        if(i==j)is=0;
    }
    cout<<ans;
}
