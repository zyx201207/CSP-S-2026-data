#include<bits/stdc++.h>
using namespace std;

long long t[200005];
char a[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>t[i]>>a[i];
    for(int i=1;i<n;i++) t[i]=t[i]+t[i-1];
    long long sum=0;
    for(int i=0;i*2<=n;i++){
            int l=0,r=n;
            for(int j=0;j*2<=n;j++){
                if(i >= t[j]){
                    l=j-1;
                    break;
                }
            }
            for(int j=n-1;(n-j-1)*2<=n;j++){
                if((n-i+1) <= t[j]){
                    r=j;
                    break;
                }
            }
            if(a[l]!=a[r]) sum++;
    }
    cout<<sum<<endl;
    return 0;
}
