#include<bits/stdc++.h>
using namespace std;

int a[200005];
char c[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
     long long l=1,r=n;
     long long num=0;
    while(l<r){
       if(a[l]>a[r]){
            int k=a[l]-a[r];
            if(c[l]!=c[r]){
                num+=a[r];
            }
            a[l]=k;
            r--;
       }else if(a[l]<a[r]){
            int k=a[r]-a[l];
            if(c[l]!=c[r]){
                num+=a[l];
            }
            a[r]=k;
            l++;
       }else{
            if(c[l]!=c[r]){
                num+=a[l];
            }
            l++;
            r--;
       }

    }
    cout<<num;

    return 0;
}//密碼 Trick||Treat!
