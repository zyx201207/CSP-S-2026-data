#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];

int How_much(){
    int next=1,now=0;
    while(a[now]==a[next]&&next<n){
        now++,next++;
    }
    return next;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
         cin>>a[i];
    }
    sort(a,a+n);
    while(m){
        int x=How_much();
        if(x<=m)for(int i=0;i<x;i++)a[i]++,m--;
        else if(m<x){
            cout<<x;
            return 0;
        }
        if(m==0){
            cout<<How_much();
            return 0;
        }
    }
    return 0;
}
