#include<bits/stdc++.h>
using namespace std;
int const MAXN=1e6+5;
char str_[MAXN];
int num[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a;
    char b;
    long long length=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>num[i]>>str_[i];
    }
    long long l=0,r=n-1;
    long long l_=0,r_=0;
    while(l<r){
        if(num[l]<num[r]){
            num[r]=num[r]-num[l];
            if(str_[l]!=str_[r]){
                ans+=num[l];
            }
            l++;
        }else if(num[l]>num[r]){
            num[l]=num[l]-num[r];
            if(str_[l]!=str_[r]){
                ans+=num[r];
            }
            r--;
        }
        else if(num[l]==num[r]){
            if(str_[l]!=str_[r]){
                ans+=num[r];
            }
            num[l]=0;
            num[r]=0;
            l++;
            r--;
        }
    }

    cout<<ans;
    return 0;
}
