#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
unsigned long long ansl=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(unsigned long long l=1,r=n,lc=0,rc=0;1;){
            if(l>=r)break;
        if(c[l]!=c[r]){
            if(a[l]-lc>a[r]-rc){
                ansl+=(a[r]-rc);
                lc+=a[r]-rc;
                r--;
                rc=0;
            }else if(a[l]-lc<a[r]-rc){
                ansl+=(a[l]-lc);
                rc+=a[l]-lc;
                l++;
                lc=0;
            }else{
                ansl+=(a[l]-lc);
                l++;r--;
                rc=0,lc=0;
            }
        }else{
            if(a[l]-lc>a[r]-rc){
                lc+=a[r]-rc;
                r--;
                rc=0;
            }else if(a[l]-lc<a[r]-rc){
                rc+=a[l]-lc;
                l++;
                lc=0;
            }else{
                l++;r--;
                rc=0,lc=0;
            }
        }

    }
    cout<<ansl;
    return 0;
}
