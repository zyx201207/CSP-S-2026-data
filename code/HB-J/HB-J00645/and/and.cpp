#include<bits/stdc++.h>
using namespace std;
const int MAXN=(int)1e5*2+100;
int a[MAXN];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int Max=0;
        for(int i=1;i<=n;i++){
            Max=max(Max,a[i]);
        }
        cout<<Max;
    }
    else if(m==n){
        int yu=a[1];
        for(int i=2;i<=n;i++){
            yu=yu&a[i];
        }
        cout<<yu;
    }
    else{
        int Min=2;
        for(int i=1;i<=19;i++){
            Min*=2;
        }
        for(int i=1;i<=n;i++){
            Min=min(Min,a[i]);
        }
        cout<<Min;
    }
    return 0;
}