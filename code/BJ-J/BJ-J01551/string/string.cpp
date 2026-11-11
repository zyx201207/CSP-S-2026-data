#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans;
long long sum;
char c[1000005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        //cout<<a[i]<<c[i];
    //    sum+=a[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            int num=min(a[l],a[r]);
            a[l]-=num;
            a[r]-=num;
            if(a[l]==0) l++;
            if(a[r]==0) r--;
        }else{
            int num=min(a[l],a[r]);
            a[l]-=num;
            a[r]-=num;
            if(a[l]==0) l++;
            if(a[r]==0) r--;
            ans+=num;
        }
    }
    cout<<ans;
    return 0;
}
