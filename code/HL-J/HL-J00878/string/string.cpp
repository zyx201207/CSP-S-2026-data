#include<bits/stdc++.h>
using namespace std;
long long a[1000000],n;char b[1000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i]>>b[i];
    long long i=1,j=n,mas=0;
    while(i<j){
        if(b[i]!=b[j]){
            if(a[i]>=a[j]){
                mas+=a[j];
                a[i]-=a[j];
                j--;
            }
            else{
                mas+=a[i];
                a[j]-=a[i];
                i++;
            }
        }
        else{
            if(a[i]>=a[j]){
                a[i]-=a[j];
                j--;
            }
            else{
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<mas;
    return 0;
}
