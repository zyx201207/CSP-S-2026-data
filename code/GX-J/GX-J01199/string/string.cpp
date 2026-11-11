#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,p=0;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        a[i]=x,b[i]=y;
    }
    int l=1,r=n;
    while(l<r){
        if(b[l]==b[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else l++,r--;
        }
        else{
            if(a[l]>a[r]){
                cnt+=a[r];
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                cnt+=a[l];
                a[r]-=a[l];
                l++;
            }
            else cnt+=a[r],l++,r--;
        }
    }
    cout<<cnt;


    return 0;
}
