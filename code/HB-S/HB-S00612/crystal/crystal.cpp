#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,a[100000000000];
long long imp,zd[10000000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1,greater<int>());
    for(int i=0;i<n;i++){
        imp=a[i];
        x=0;
        for(int j=0;j<n;j++){
            if(j=i)break;
            x+=imp-a[j];
            if(x<=m){
                zd[i]++;
            }
            else{
                break;
            }
        }
    }
    sort(zd,zd+n+1,greater<int>());
    cout<<zd[0];
    return 0;
}