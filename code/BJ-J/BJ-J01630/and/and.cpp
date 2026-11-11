#include<iostream>
#include<algorithm>
using namespace std;


const int N=2e5+10;
int f[N];

int n,m;


bool cmp(int a,int b){
    return a>b;

}
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    sort(f+1,f+n+1,cmp);
    ans=f[1];
    for(int i=2;i<=m;i++){
        ans &=f[i];
    }

    cout<<ans;
    return 0;
}
