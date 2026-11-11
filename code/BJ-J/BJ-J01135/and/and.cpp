#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;
int n,m;
bool bb[200010][31];
int xxx[200010],q[200010];
int ans=2147483647;

void bio(int l,int x){
    int cnt=0;
    while(x>0){
        bb[l][31-cnt]=x%2;
        x=(x>>1);
        cnt++;
    }
}

int fid(int c){
    int cnt;
    for(int i=1;i<=n;i++){
        if(bb[i][c]==1)cnt++;
    }
    return cnt;
}

void coll(int t){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(bb[i][t]==1){
            q[cnt]=i;
            cnt++;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        xxx[i]=x;
        bio(i,x);//10=>2
    }

    for(int i=1;i<=31;i++){
        if(fid(i)==m){
            coll(i);
            break;
        }
    }
    for(int i=0;i<m;i++){
        int x=ans & xxx[q[i]];
        cout<<ans<<" "<<xxx[q[i]]<<" "<<q[i]<<endl;
        ans=x;
    }
    cout<<ans<<endl;
    return 0;
}
