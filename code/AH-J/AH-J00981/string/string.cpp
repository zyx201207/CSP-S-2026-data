#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long sum;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    int l=0,r=n-1;
    long long a[n+5];
    char c[n+5];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        cin>>c[i];
    }
    while(l<r){
        if(c[l]!=c[r]){
            sum+=min(a[l],a[r]);
        }
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }else if(a[r]>a[l]){
            a[r]-=a[l];
            l++;
        }else{
            l++;
            r--;
        }
    }
    printf("%lld",sum);

    return 0;
}
