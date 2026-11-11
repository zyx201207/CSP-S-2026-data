#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N];
int ans=-1,chs[N],use[N];

bool a1(int x){
    while(x){
        if(x%2==0)return 0;
        x/=2;
    }
    return 1;
}

int c1(int x){
    int cnt=0;
    while(x){
        if(x%2==1)cnt++;
        x/=2;
    }
    return cnt;
}

void testA(int x){//test 1~10
    if(x>m){
        int ad=a[chs[1]];
        for(int i=2;i<=m;i++){
            ad=ad&a[chs[i]];
        }
        ans=max(ans,ad);
        return;
    }
    for(int i=chs[x-1]+1;i<=n;i++){
        if(!use[i]){
            use[i]=1;
            chs[x]=i;
            testA(x+1);
            use[i]=0;
        }
    }
}
void testB(){//test 11~15
    sort(a+1,a+1+n);
    int ad=a[n];
    for(int i=1;i<m;i++){
        ad=ad&a[n-i];
    }
    ans=ad;
}

int main(){
    bool spA=1,spB=1;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a1(a[i])==0)spA=0;
        if(a[i]!=i-1)spB=0;
    }
    if(n<=2000){
        testA(1);
        cout<<ans;
    }else if(spA==1||n-1==m||(spB==1&&c1(n)==1)){
        testB();
        cout<<ans;
    }else{
        testA(1);
        cout<<ans;
    }
    return 0;  
}