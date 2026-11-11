#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[200005];
    char c[200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long cnt=0;
    int i=1,j=n+1-i;
    while(i<j){
        if(a[i]>a[j]){
            a[i]-=a[j];
            if(c[i]!=c[j]){
                cnt+=a[j];
            }
            j--;
        }
        else if(a[i]==a[j]){
            if(c[i]!=c[j]){
                cnt+=a[i];
            }
            i++;j--;
        }
        else{
            a[j]-=a[i];
            if(c[i]!=c[j]){
                cnt+=a[i];
            }
            i++;
        }
    }
    cout<<cnt;
    return 0;
}
