#include<bits/stdc++.h>
using namespace std;
int m1[100005],ni[100005];
void b(int x,int y){
    while(y){
        y--;
        int maxx=0;
        for(int i=1;i<=x;i++){
                m1[i]=1;
            if(ni[i]>maxx){
                maxx=ni[i];
        ni[i]==0;
            }
        }ml[y+1]=maxx;
    }return 0;

}
int main(){
    freopen("and.in","t",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ni[i];
    }b(n,m);
    int ans=1;
    for(int i=1;i<=m;i++){
        ans&=m1[i];
    }cout<<ans;
return 0;
}
