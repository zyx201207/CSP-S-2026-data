#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
long long ans,an;
long long C=1,check;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=0;i<32;i++){
        C*=2;
    }
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    ans=a[0];
    for(int i=1;i<m;i++){
        an=0;
        check=C;
        while(check>=1){
            if(ans>=check&&a[i]>=check){
                an+=check;
            }
            if(a[i]>=check){
                a[i]-=check;

            }
            if(ans>=check){
                ans-=check;

            }

            check/=2;
        }
        ans=an;
    }
    cout<<ans;
    return 0;
}
