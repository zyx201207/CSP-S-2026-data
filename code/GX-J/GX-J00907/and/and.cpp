#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,l[10005],f[10005];
    int ans=0,m1=1;
    cin>>n,m;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        f[i]=l[i];
    }
    ans=l[1];
    l[1]=0;
    for(int j=1;j<=n;j++){
        if((ans<(ans&f[j]))&f[j]!=0){
            ans=(ans&f[j]);
            f[j]=0;
            m1+=1;
        }
        if(m1==m){
            cout<<ans;
            return 0;
        }
    }
}

