#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
int main(){
    freopen("and.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long p=0;
    for(int i=30;i>=0;i--){
        p=0;
        for(int f=1;f<=n;f++){
            if((a[f]&(1<<i))!=0){
                p++;
            }
        }
        if(p>=m){
            for(int f=1;f<=n;f++){
                if((a[f]&(1<<i))==0) a[f]=0;
            }
        }
    }
    p=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            p=a[i];
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=0){
            p=p&a[i];
        }
    }
    freopen("and.out","w",stdout);
    cout<<p;
}