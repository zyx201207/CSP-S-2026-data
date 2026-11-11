#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],k;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    cout<<a[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
