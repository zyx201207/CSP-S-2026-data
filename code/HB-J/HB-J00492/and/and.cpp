#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int e[31];
void l2(int x){
    int cnt=0;
    while(x>=1){
        e[cnt++]+=x%2;
        x/=2;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n,cmp);
    for(int i=0;i<m;i++){
        l2(a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(e[i]==m){
            ans+=pow(2,i);

        }
    }
    cout<<ans;
    return 0;
}












