#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int l=1,r=n;
    long long cntl=a[1];
    long long cntr=a[n];
    for(;l<r;){
        if(c[l]==c[r]){
            if(cntl<=cntr){
                cntr-=cntl;
                l++;
                cntl=a[l];
            }else{
                cntl-=cntr;
                r--;
                cntr=a[r];
            }
        }
        else{
            if(cntl<=cntr){
                cntr-=cntl;
                ans+=cntl;
                l++;
                cntl=a[l];
            }else{
                cntl-=cntr;
                ans+=cntr;
                r--;
                cntr=a[r];
            }
        }
    }
    cout<<ans;
    return 0;
}
