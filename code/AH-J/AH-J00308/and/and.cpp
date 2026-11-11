#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009],ans;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    //cout<<ans<<'\n';
    for(int i=1;i<=m;i++){
        ans=ans&a[i];
        //cout<<ans<<' '<<a[i]<<endl;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
