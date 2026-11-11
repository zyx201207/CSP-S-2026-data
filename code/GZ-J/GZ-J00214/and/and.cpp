//GZ-J00214  赵子航  贵阳市第三中学
#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
    return a>b;
}
int main(){
//    freopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1],b[200000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1+m;j<=n;j++){
            b[i]+=&(a[i],a[j]);
        }
    }
    sort(b+1,b+length(b)+1,f)
    cout<<b[0];
//    fclose(stdin);
//    fclose(stdout);
    return 0;
}
