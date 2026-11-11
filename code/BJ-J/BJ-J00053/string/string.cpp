#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
pair<ll,ll>a[200005];
char c[200005];
long long len,r,p,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p>>c[i];
        len+=p;
        a[i].first=a[i-1].second+1;
        a[i].second=a[i-1].second+p;
    }
    r=len;
    int j=n;
    for(int i=1;i<j;i++){
        while(a[i].second>len-a[j].first+1){
            if(c[i]!=c[j]){
                ans+=r-a[j].first+1;
            }
            r=a[j].first-1;
            j--;
        }
        if(c[i]!=c[j]){
            ans+=r-(len-a[i].second+1)+1;
        }
        r=(len-a[i].second+1)-1;
        if(r<a[j].first)j--;
    }
    cout<<ans;
    return 0;
}
