#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n=0,a[211111],ans=0;
    char c[211111];
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n,ls=0,rs=0;
    while(l<r){
        if(ls>0){
            if(c[l]==c[r]){
                if(ls>a[r]){
                    ls=ls-a[r];
                    r--;
                }
                else{
                    rs=a[r]-ls;
                    l++;
                }
            }
            else if(c[l]!=c[r]){
                if(ls>a[r]){
                    ls=ls-a[r];
                    ans+=a[r];
                    r--;
                }
                else{
                    rs=a[r]-ls;
                    ans+=ls;
                    l++;
                }
            }
        }
        else if(rs>0){
            if(c[l]==c[r]){
                if(a[l]>rs){
                    ls=a[l]-rs;
                    r--;
                }
                else{
                    rs=rs-a[l];
                    l++;
                }
            }
            else if(c[l]!=c[r]){
                if(a[l]>rs){
                    ls=a[l]-ls;
                    ans+=rs;
                    r--;
                }
                else{
                    rs=rs-a[l];
                    ans+=a[l];
                    l++;
                }
            }
        }
        else if(c[l]==c[r]){
            if(a[l]>a[r]){
                ls=a[l]-a[r];
                r--;
            }
            else{
                rs=a[r]-a[l];
                l++;
            }
        }
        else if(c[l]!=c[r]){
            if(a[l]>a[r]){
                ls=a[l]-a[r];
                ans+=a[r];
                r--;
            }
            else{
                rs=a[r]-a[l];
                ans+=a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}

