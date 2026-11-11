//GZ-J00231,遵义市第十二中学,韩冰洁
#include<bits/stdc++.h>
using namespace std;
int n,x;
string s;
int jc(int x){
    int sum=1;
    for(int i=1;i<=x;i++){
        sum=sum*i;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>x;
    struct m[200005]{
      int sz;
      string e,e1;
    };
    for(int i=1;i<=n;i++){
        cin>>m.sz[i];
        while(m.sz[i]>0){
            m.e+=m.sz[i]%2+'0';
            m.sz[i]=m.sz[i]/2;
        }
    }
    for(int i=1;i<n;i++){
        m.sz[i]+=m.sz[i+1];
    }
    for(int i=1;i<=n;i++){
        cout<<m.sz[i];
    }
    return 0;
}
