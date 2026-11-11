#include<bits/stdc++.h>
using namespace std;
long long a[100000005],s2[100000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,max=-1;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(long long i=n-1;i>=0;i--){
        long long s=0,s1=0;
        for(long long j=0;j<n;j++){
                if(a[i]>a[j]){
                    s=s+a[i]-a[j];
                }else{
                    i--;
                    break;
                }
            s1++;
            if(s==m){
                s2[i]=s1;
            }
        }
    }
    for(long long i=n-1;i>=0;i--){
        for(long long j=0;j<n;j++){
            if(a[i]==a[j]){
                s2[i]+=1;
            }
        }
    }
    for(long long i=0;i<n;i++){
        if(max<s2[i]){
            max=s2[i];
        }
    }
    cout<<max;
    return 0;
}
