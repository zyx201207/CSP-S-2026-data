#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,p,s=0,m,b;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
            p=a[i]&a[i+1];
            if(p>s){
            s=p;
            b=i;
            }
    }
    a[b]=-1;
    for(int j=3;j<=m;j++){
        for(int i=0;i<n;i++){
                if(a[i]==-1) break;
            p=a[i]&s;
            if(p>s){
                s=p;
                b=i;
            }

        }
        b=-1;
    }

    cout<<s;
    return 0;
}

