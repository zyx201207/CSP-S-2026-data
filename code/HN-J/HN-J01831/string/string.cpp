#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
    long long n,a[200005];
    char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    long long l=1,r=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        r+=a[i];
    }
    //cout<<r;
    long long ans=0;
    long long j=0,k=n-1;
    while(l<=r){
        long long mi=min(a[j],a[k]);
        if(c[j]!=c[k]){


            ans+=mi;
            a[j]-=mi;
            a[k]-=mi;
        }
        if(a[j]==0){
            j++;
        }
        if(a[k]==0){
            k--;
        }
        l+=mi;
        r-=mi;
        //cout<<"1";

    }


    cout<<ans;








    return 0;
}
