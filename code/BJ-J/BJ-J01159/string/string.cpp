#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
struct Q{
    int a;
    char c;
}m[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i].a>>m[i].c;
    }for(int i=1;i<=n/2;i++){
        if(m[i].c!=m[n-i+1].c){
            if(m[i].a>m[n-i+1].a){
                cnt+=m[n-i+1].a;
            }else if(m[i].a<m[n-i+1].a){
                cnt+=m[i].a;
            }else{
                cnt+=m[n-i+1].a;
            }
        }
    }cout<<cnt;
    return 0;
}
