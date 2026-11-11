#include<bits/stdc++.h>
using namespace std;
int a[50000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int b=1;
    int n;
    int o=0;
    long long m;
    int y=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
            b=1;
        for(int s=1;s<=m;s++){
            int x=a[j];
            for(int h=1;h<=n;h++){
                if(x==a[h]){
                b+=1;
                }
            }
        }
    }
    cout<<b/2;
    return 0;
}
