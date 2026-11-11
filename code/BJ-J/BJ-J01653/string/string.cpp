#include<bits/stdc++.h>
using namespace std;
int n,a[220000];
long long sum=0;
char c[220000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        scanf("%c%c",&c[i],&c[i]);
    }
    int l=1,r=n;
    while(l<r){
        if(a[l]==a[r]){
            if(c[l]!=c[r])sum+=a[l];
            l++,r--;
        }
        else if(a[l]<a[r]){
            if(c[l]!=c[r])sum+=a[l];
            a[r]-=a[l];
            l++;
        }
        else{
            if(c[l]!=c[r])sum+=a[r];
            a[l]-=a[r];
            r--;
        }
    }
    printf("%lld",sum);
    return 0;
}
