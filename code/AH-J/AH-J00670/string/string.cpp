#include<iostream>
#define int long long
using namespace std;
int N;
int a[200005];
char c[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=N,ans=0;
    while(l<r){
        if(a[l]>a[r]){
            ans+=(c[l]==c[r]?0:1)*a[r];
            a[l]-=a[r];
            r--;
        }else if(a[l]==a[r]){
            ans+=(c[l]==c[r]?0:1)*a[r];
            l++;
            r--;
        }else if(a[l]<a[r]){
            ans+=(c[l]==c[r]?0:1)*a[l];
            a[r]-=a[l];
            l++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
