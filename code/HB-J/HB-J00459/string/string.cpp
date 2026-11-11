#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],l,r,cnt;
string s,x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>x;
        s+=x;
    }
    l=0;
    r=s.size();
    while(l<=r){
        if(s[l]!=s[r]){
            if(a[l]>=a[r]){
                a[l]-=a[r];
                cnt=cnt+a[r];
                a[r]=0;
            }else{
                a[r]-=a[l];
                cnt=cnt+a[l];
                a[l]=0;
            }
        }else{
            if(a[l]>=a[r]){
                a[l]-=a[r];
                a[r]=0;
            }else{
                a[r]-=a[l];
                a[l]=0;
            }
        }
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<cnt;
    return 0;
}
