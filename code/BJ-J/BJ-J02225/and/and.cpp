#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,x,b[200005][35],c[35],d[35],ans;
queue<long long> q[35];
void dp(){
    while(x>0){
        for(int i=0;i<x;i++){
            c[i]=0;
            while(!q[i].empty())q[i].pop();
        }
        while(!q[x].empty()){
            long long bb=q[x].front(),aa=a[q[x].front()],j=-1;
            q[x].pop();
            while(!aa==0){
                j++;
                if(aa%2==1)q[j].push(bb);
                c[j]+=aa%2;
                aa/=2;
                if(j==x-1)break;
            }
        }
        x--;
        for(;x>=0;--x){
            if(c[x]>=m){
                ans+=d[x];
                break;
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    d[0]=1;
    x=30;
    for(int i=1;i<=30;i++){
        d[i]=2*d[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q[30].push(i);
    }
    dp();
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
