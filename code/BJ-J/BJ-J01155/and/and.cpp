#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+1+n);
        cout<<a[n];
    }else{
        maxx=a[1]&a[2];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=j){
                    if((a[i]&a[j])>maxx){
                        maxx=a[i]&a[j];
                    }
                }
            }
        }
        cout<<maxx;
    }

}

