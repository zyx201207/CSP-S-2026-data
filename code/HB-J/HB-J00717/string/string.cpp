#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m=0,s=0,sum=0;
char c[200005],u='0';
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        if(m<a[i]){
            if(u==c[i])m+=a[i];
            else m=a[i],u=c[i];
        }
        else if(u==c[i])m+=a[i];
    }
    sum-=m;
    if(sum&1)cout<<sum-1;
    else cout<<sum;
    return 0;
}
