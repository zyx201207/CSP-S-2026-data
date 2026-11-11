#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long e=0;
    long long maxn=-1;
    long long m=0;
    int a,b;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        int n;
        cin>>n;
        if(i==1){
            m=n;
        }else if(i>1){
            e=m&n;
            m=n;
         if(maxn<e){
            maxn=e;
            }
        }
    }
    cout<<maxn;
}
