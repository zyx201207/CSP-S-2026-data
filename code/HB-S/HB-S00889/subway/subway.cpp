#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    vector<int>v(m+1,0);
    for(int i=1;i<=m;i++)cin>>v[i];
    for(int i=0;i<p;i++)cout<<2*v[1]<<endl;
    return 0;
}
