#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[2*100000+10],b[2*100000+10];

bool cmp(int x,int y){
    return x >y;
}

int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    int nm=0;
    for(int i=1;i<=m;i++){
       nm&=a[i];
    }
    cout << nm;
    return 0;
}
