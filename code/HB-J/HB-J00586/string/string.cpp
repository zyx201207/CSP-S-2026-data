#include <bits/stdc++.h>
using namespace std;
long long n,cnt,sum,pos;
char a[200005];
int b[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>b[i]>>a[i];
    }
    int l = 0,r = n-1;
    while(l<r){
        if(a[l]==a[r]){
            if(b[l]>b[r]){
                b[l]-=b[r];
                b[r] = 0;
                r--;
            }
            else{
                b[r]-=b[l];
                b[l] = 0;
                l++;
            }
        }
        else{
            if(b[l]>b[r]){
                b[l]-=b[r];
                cnt+=b[r];
                b[r] = 0;
                r--;
            }
            else{
                b[r]-=b[l];
                cnt+=b[l];
                b[l]=0;
                l++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
