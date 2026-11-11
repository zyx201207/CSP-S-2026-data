#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
    freeopen("string.in","r",stdin);
    freeopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>a[i]>>c[i];
    }
    long long l = 1,r = n,cntl = a[1],cntr = a[n];
    while(l<=r){
        if(c[l] == c[r]){
            if(cntl==cntr){
                l++;
                r--;
                cntl = a[l];
                cntr = a[r];
            }
            else if(cntl>cntr){
                r--;
                cntl-=cntr;
                cntr = a[r];
            }
            else{
                l++;
                cntr-=cntl;
                cntl = a[l];
            }
        }
        else{
            if(cntl==cntr){
                ans+=cntl;
                l++;
                r--;
                cntl = a[l];
                cntr = a[r];
            }
            else if(cntl>cntr){
                r--;
                cntl-=cntr;
                ans+=cntr;
                cntr = a[r];
            }
            else{
                l++;
                cntr-=cntl;
                ans+=cntl;
                cntl = a[l];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}