#include<bits/stdc++.h>
using namespace std;
const int N=100050;
int a,b;
bool ans[5]={0,0,0,0,0};
char a1,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>a1>>b>>b1;
    if(a==b) ans[1]=1;
    for(int i=1;i<=4;i++) cout<<ans[i];
    return 0;
}
