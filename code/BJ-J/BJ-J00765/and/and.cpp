#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,a[500005],str[500005];
    int r;
    cin>>n;
    cin>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        str[i]=a[i];


    }
    long long maxn=0,_2930gpc=0;//=15&8;
    sort(a+1,a+n+1);

    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(i>1)str[k]=maxn;
                _2930gpc=a[j]&str[k];
                if(_2930gpc>maxn){
                    maxn=_2930gpc;
                }
            }
        }

    }
    cout<<maxn;
    return 0;
}
