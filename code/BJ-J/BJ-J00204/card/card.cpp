#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int main()
{
    int n,m;
    cin>>n>>m;
    int dot[N],ans[N]={0};
    for(int y=1;y<=n;y++){
        cin>>dot[y];
        ans[dot[y]]+=y;
        }
    for(int y=1;y<=m;y++)
        cout<<ans[y]<<" ";
    
}