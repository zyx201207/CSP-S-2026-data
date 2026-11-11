#include<bits/stdc++.h>
using namespace std;
long long a[200005],m=0,n,k=1,d;
char b[200005],lis[1000000009];
int main(){
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        d+=a[i];
        for(int j=1;j<=a[i];j++){
            lis[k++]=b[i];
        }
    }
    for(int i=1;i<=d/2;i++){
        //cin>>lis[i]>>b[i];
        if(lis[i]!=lis[d-i+1])m+=1;
    }
    cout<<m;
    return 0;
}
