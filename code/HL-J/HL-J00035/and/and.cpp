#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],b[200009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    b[i]=a[i]&a[j];
            }
        }sort(b+1,b+n+1);
        cout<<b[n];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;

}

