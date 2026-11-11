#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt;string s,str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>s,str+=s;
    for(int l=0,r=n-1;l<r;){
        if(str[l]!=str[r])cnt+=min(a[l],a[r]);
        if(a[l]==a[r])a[r]=0,a[l]=0,l++,r--;
        else if(a[l]<a[r])a[r]-=a[l],a[l]=0,l++;
        else if(a[l]>a[r])a[l]-=a[r],a[r]=0,r--;
    }cout<<cnt;
    return 0;
}
