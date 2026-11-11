
#include<bits/stdc++.h>
using namespace std;
struct student{
    int a;
    int w[32];
    int g;
}q[200010];
long long n,m;
int cnt[32];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>q[i].a;
    }
    cout<<q[n].a;
    return 0;
}