#include<bits/stdc++.h>
using namespace std;
char a[10000000];
int b[200001];
char c[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x=0,sum=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>b[i]>>c[i];
        for(int j=0;j<b[i];++j){
            a[x]=c[i];
            ++x;
        }
    }
    --x;
    for(int i=0;i<=x/2;++i){
        if(a[i]!=a[x-i]){
            ++sum;
        }
    }
    cout<<sum;
    return 0;
}
