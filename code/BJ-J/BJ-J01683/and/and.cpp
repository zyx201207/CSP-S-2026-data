#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int a[N],maxx;
int n,m;
void and1(int t,int x){
    if(t==0){
        maxx=max(maxx,x);
        return ;
    }
    for(int i=m-t+1;i<=n-t+1;i++){
        if(t==m) x=a[i];
        else x=x&a[i];
        and1(t-1,x);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    and1(m,0);
    cout << maxx;
    return 0;
}

