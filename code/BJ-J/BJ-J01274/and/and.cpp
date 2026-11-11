#include<bits/stdc++.h>
using namespace std;
const int M=2e5+2;
int l[M],n,ma=0,m;
int ws(int n){
    int js=0;
    while(n){
        n/=2;
        js++;
    }
    return js;
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>l[i];
    sort(l,l+n,cmp);
    for(int i=0;i<=n-m;i++){
        int jj=0,w=l[i];
        for(int j=0;j<m-1;j++){
            if(ws(l[i+j])==ws(l[i+j+1])) jj++;
            w&=l[i+j+1];
        }
        if(jj==m-1){
            cout<<w;
            return 0;
        }
        ma=max(ma,w);
    }
    cout<<ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
