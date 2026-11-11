#include<bits/stdc++.h>
using namespace std;
int n,m,aa[200005];
int pick(int n,int m,int i,int a,int cnt){
    if(a==0){
        cnt+=aa[i];
        return pick(n,m,i-1,a+1,cnt);
    }
    else if(m-a){
        int maxx=-1;
        for(int j=i;j>=m-a;j--){
            maxx=max(maxx,pick(n,m,j,a+1,cnt&aa[j]));
        }
        return maxx;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>aa[i];
    }
    int maxx=-1;
    //sort(aa+1,aa+1+n);
    for(int i=n;i>=m+1;i--){
        maxx=max(maxx,pick(n,m,i,0,0));
    }
    cout<<maxx;
    return 0;
}
