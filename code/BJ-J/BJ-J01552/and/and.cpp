#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200001]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(a[j]>a[j-1]){
                int ans;
                ans=a[j];
                a[j]=a[j-1];
                a[j-1]=ans;
            }
        }
    }
    cout<<a[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
