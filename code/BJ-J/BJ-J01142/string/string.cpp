#include<bits/stdc++.h>
using namespace std;
int b[200010];
char w[200010];
long long n,a,cnt=0;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a>>c;
        b[i]=a;
        w[i]=c;
    }
    long long  l=0,r=n-1;
    while(l<r){
        if(b[l]<b[r]){
            if(w[l]!=w[r])cnt+=b[l];
            b[r]-=b[l];
            b[l]=0;
            l++;
        }else if(b[r]<b[l]){
            if(w[l]!=w[r])cnt+=b[r];
            b[l]-=b[r];
            b[r]=0;
            r--;
        }else{
            if(w[l]!=w[r])cnt+=b[l];
            b[r]=0;
            b[l]=0;
            l++;
            r--;
        }
    }
    cout<<cnt;

    return 0;
}