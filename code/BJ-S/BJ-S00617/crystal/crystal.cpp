#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m;
cin>>n>>m;
int a[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
sort(a,a+n);
int maxn=0;
for(int i=0;i<n;i++){
        int cnt=0;
        int tmp=m;
for(int j=i;j>=0;j--){
        if(a[j]<=a[i]){
            int ma=a[i]-a[j];
             if(tmp-ma>=0){
                tmp-=ma;
                cnt++;
                if(cnt>maxn){
                maxn=cnt;
                }
            }
        }

}
}

cout<<maxn;
return 0;
}
