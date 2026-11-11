#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
int a[200005];
bool v[200005];

int f(int dep,int x){
    int max=-1;
    if(dep==m+1) return x;
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            int h = a[i];
            v[i] = 1;
            f(dep+1,h);
            v[i] = 0;
            ans = x&h;
            if(ans>=max) max=ans;
        }

    }
    return max;
}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int max=-1;
        for(int i=1;i<=n;i++){
            if(a[i] >= max) max = a[i];
        }
        cout<<max;
    }
    else{
        int max=-1,ans;
        for(int i=1;i<=n;i++){
            v[i] = 1;
            ans = f(2,a[i]);
            v[i] = 0;
            if(ans>=max) max=ans;
        }
        cout<<max;
    }

    return 0;
}
