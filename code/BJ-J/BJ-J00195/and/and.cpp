#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,a[N],s[N][32],mj,b[40],c[N],d[N];
long long ans = 0;
void zh(int x,int i){
     int k;
     int j = 0;
     while(x>=1){
         k = x%2;
         x = x/2;
         s[i][j] = k;
         b[j]++;
         j++;
     }
     j--;
     if(j>mj&&b[j]>=m) mj = j;
     //cout<<j<<" "<<mj<<" "<<b[j]<<endl;
     return;
}
bool cmp(int x, int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        c[i] = i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i<=n;i++){
        zh(a[i],i);
    }
    //cout<<b[3]<<endl;
    //cout<<mj<<endl;
    int t = n, l;
    while(mj>=0){
        l = 0;
        for(int i = 1;i<=t;i++){
            if(s[c[i]][mj] == 1){
                l++;
                d[l] = c[i];
            }
        }
        if(l>=m){
            t = l;
            for(int i = 1;i<=t;i++){
                c[i] = d[i];
            }
            ans+=pow(2,mj);
        }
        mj--;
    }
    cout<<ans<<endl;
    return 0;
}
