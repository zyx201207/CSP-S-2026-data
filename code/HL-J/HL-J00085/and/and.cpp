#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
    }
    else if(m==2){
        int ma=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ma<(a[i]&a[j])) ma=(a[i]&a[j]);
            }
        }
        cout<<ma;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

