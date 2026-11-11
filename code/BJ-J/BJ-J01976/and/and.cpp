#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxx;
long long a[200005];
void search_max(int x,int step,long long ax){
    if(step>m){
        maxx=max(maxx,ax);
        return;
    }
    for(int i=x;i<=n-m+step;i++){
        if(step==1){
            ax=a[i];
        }
        ax=(ax&a[i]);
        search_max(i+1,step+1,ax);
    }
    return;

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    search_max(1,1,0);
    cout<<maxx;
    return 0;
}
