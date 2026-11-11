#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],ans=0;
char b[1000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    for(int i=0,j=n-1;i<=j;){
        if(b[i]!=b[j])ans+=min(a[i],a[j]);
        if(a[i]>=a[j]){
            a[i]-=a[j];
            j--;
        }else{
            a[j]-=a[i];
            i++;
        }
    }
    cout<<ans;
}
