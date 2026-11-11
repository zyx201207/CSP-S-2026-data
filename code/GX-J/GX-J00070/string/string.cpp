#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long ans;
char c[200005];
unsigned long long a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int l=0,r=n;
    while(true){
        if(l==r){
            break;
        }
        if(c[l]!=c[r]){
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                a[r]=0;
                r--;
            }else{
                if(a[l]<a[r]){
                    ans+=a[l];
                    a[r]-=a[l];
                    a[l]=0;
                    l++;
                }
                else{
                    if(a[l]==a[r]){
                        ans+=a[l];
                        a[r]=0;
                        a[l]=0;
                        l++;r--;
                    }
                }
            }
        }else{
            if(a[l]==a[r]){
                a[l]=0;
                a[r]=0;
                l++;r--;
            }else{
                if(a[l]>a[r]){
                    a[l]-=a[r];
                    a[r]=0;
                    r--;
                }else{
                    if(a[l]<a[r]){
                        a[r]-=a[l];
                        a[l]=0;
                        l++;
                    }
                }
            }
        }
    }
    cout<<ans;
}
