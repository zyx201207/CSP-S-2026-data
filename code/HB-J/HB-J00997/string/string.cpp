#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    long long sum=0,k=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    sum=sum/2;
    //for(int i=1;i<=n;i++){
     //   cout<<a[i]<<"\n";
    //}
    //cout<<sum<<"\n";
    for(int i=1,j=n;;){
        //cout<<k<<"\n";
        if(k>=sum)break;
        //cout<<k<<"\n";
        if(b[i]!=b[j]){
            if(a[i]==a[j]){
                ans+=a[i];
                k+=a[i];
                i++;
                j--;
            }
            else if(a[i]>a[j]){
                ans+=a[j];
                k+=a[j];
                a[i]-=a[j];
                j--;
            }
            else{
                ans+=a[i];
                k+=a[i];
                a[j]-=a[i];
                i++;
            }
        }
        else{
            if(a[i]==a[j]){
                k+=a[i];
                i++;j--;
            }
            else if(a[i]>a[j]){
                k+=a[j];
                a[i]-=a[j];
                j--;
            }
            else{
                k+=a[i];
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
