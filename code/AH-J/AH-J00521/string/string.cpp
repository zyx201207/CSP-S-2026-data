#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int r,l;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    r=n;
    l=1;
    while(l<r){
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                sum+=a[r];
            }
            a[l]-=a[r];
            a[r]-=a[r];
            r--;
        }else if(a[l]<a[r]){
            if(c[l]!=c[r]){
                sum+=a[l];
            }
            a[l]-=a[l];
            a[r]-=a[l];
            l++;
        }else{
            if(c[l]!=c[r]){
                sum+=a[l];
            }
            a[l]-=a[l];
            a[r]-=a[l];
            l++;
            r--;
        }
    }
    cout<<sum;
    return 0;
}
