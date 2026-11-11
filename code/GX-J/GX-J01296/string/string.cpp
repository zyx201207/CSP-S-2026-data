#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout)
    long long n,a[200001],num,sum=0;
    char str[200001];
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>num>>str[i];
        sum+=num;
        a[i]=num;
    }
    long long l=0,r=0,linx=1,rinx=n,cnt=0;
    for(long long i=1;i<(sum+1)/2;i++){
        l++;r++;
        if(str[linx]!=str[rinx]){
            cnt++;
        }
        if(l==a[linx]){
            l=0;
            linx++;
        }
        if(r=a[rinx]){
            r=0;
            rinx--;
        }
    }
    cout<<cnt;
    return 0;
}
