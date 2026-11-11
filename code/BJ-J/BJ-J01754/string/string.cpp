#include<bits/stdc++.h>
using namespace std;
struct s{
    int a;
    char c;
}p[200005];
int main(){
    int n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].a>>p[i].c;
    }
    if(n==1){
        cout<<0;
    }
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,p[i].a);
    }
    cout<<mx;
    return 0;
}
