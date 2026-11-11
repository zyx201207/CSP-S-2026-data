#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen(crystal.in,"r",stdin);
    freopen(crystal.out,"w",stdout);
    int n,m,num=0,a[100005];
    cin>>n;
    cin>>m;
    for(int i=0;i<=n-1;i++){
            cin>>a[i];
        if(a[i]<a[i+1]){
            a[i]+=a[i+1]-a[i];
            if(a[i]==a[i+1]){
                m++;
            }
            m--;
            num+=1;
            if(m==0){
                break;
            }
        }
    }
    cout<<num;
    return 0;
}
