#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],maxn;
bool check(int x){
    for(int i=1;i<=n-x+1;i++){
        int sum=0;
        for(int j=i;j<i+x-1;j++){
            sum+=a[i+x-1]-a[j];
            if(sum>m){
                break;
            }
        }
        if(sum<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=1,len=0,sum=0,maxn=0;
    while(r<=n){
        len++;
        r++;
        sum+=len*(a[r]-a[r-1]);
        while(sum>m&&l<r){
            sum-=(a[r]-a[l+1]);
            l++;
            len--;
        }
        maxn=max(maxn,len+1);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
