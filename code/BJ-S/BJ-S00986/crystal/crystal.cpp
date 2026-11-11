#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL a[N],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    LL cnt=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<n;i++){
        LL sub=1,subm=m;
        for (int j=i-1;j>=0;j--){
            if(a[i]-a[j]>subm)break;
            else {
                sub++;
                subm-=a[i]-a[j];
            }
        }
    cnt=max(sub,cnt);
    }
    cout<<cnt;
    return 0;
}
