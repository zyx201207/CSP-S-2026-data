#include<bits/stdc++.h>
using namespace std;
long long int a[1000001];
int b[1000001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long int num=0,cnt=0;
    int maxx=-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(num==m){
                b[i]=cnt;
                break;
            }else if(num>m){
                b[i]=cnt-a[j-1]+a[i-1];
                break;
            }
            if(a[j]-a[i]<=m){
                num+=a[j]-a[i];
                cnt++;
            }
        }
        maxx=max(b[i],maxx);
    }
    if(maxx>n){
        cout<<n;
        return 0;
    }
    cout<<maxx;
    return 0;
}



