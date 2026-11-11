#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans;
void And(int a){
    ans=ans & a;
}bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n,cmp);
    ans=a[0];
    for(int i=1;i<m;i++){
        And(a[i]);
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
