#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long ans=0;
    int i=1,j=n;
    while(i<j){
        if(c[i]==c[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        else{
            ans+=min(a[i],a[j]);
            if(a[i]>a[j]){
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
            else{
                i++;
                j--;
            }
        }
    }
    cout<<ans;
}