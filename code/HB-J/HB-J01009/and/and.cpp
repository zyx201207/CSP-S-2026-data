#include <bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
int n,m,x=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<"0";
    }else{
        for(int i=1;i<=n;i++){
            int num=a[i];
            for(int j=1;j<=n;j++){
                if(i!=j){
                    b[x]=a[i]&&a[j];
                    x++;
                }
            }
            a[i]=num;
        }
        sort(b+1,b+x+1);
        cout<<b[x];
    }
    return 0;
}
