#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
int n,a[N];
char c[N];
long long sum=0;
void ff(int l,int r){
    if(l>=r){
        return ;
    }
    if(a[l]==a[r]&&c[l]==c[r]){
        ff(l+1,r-1);
    }else if(a[l]==a[r]&&c[l]!=c[r]){
        sum+=a[l];
        ff(l+1,r-1);
    }else if(a[l]!=a[r]&&c[l]==c[r]){
        if(a[l]>a[r]){
            a[l]-=a[r];
            ff(l,r-1);
        }else{
            a[r]-=a[l];
            ff(l+1,r);
        }
    }else{
        if(a[l]>a[r]){
            a[l]-=a[r];
            sum+=a[r];
            ff(l,r-1);
        }else{
            a[r]-=a[l];
            sum+=a[l];
            ff(l+1,r);
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ff(1,n);
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
