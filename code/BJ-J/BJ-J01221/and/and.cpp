#include<bits/stdc++.h>
using namespace std;
long long n,m,p=0;
long long a[200002];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            p=max(p,a[i]);
        }
        cout<<p;
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                p=max(p,a[i]&a[j]);
            }
        }
        cout<<p;
    }
    if(m==n){
        for(int i=0;i<n;i++){
            p=p&a[i];
        }
        cout<<p;
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
