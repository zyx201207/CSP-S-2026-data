#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n;
long long a[MAXN],m,s[MAXN];
bool check(int l,int r,long long tar){
    long long sum=s[r]-s[l-1];
    long long wap=(r-l+1ll)*tar-sum;
    return (wap<=m)?true:false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n >>m;
    for(int i=1;i<=n;i++) cin >>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int i=1,j=1;
    int ans=1;
    while(j<=n&&i<=j){
        if(check(i,j,a[j])){
            ans=max(ans,j-i+1);
            j++;
        }else{
            i++;
        }
    }
    cout <<ans <<endl;
    return 0;
}
