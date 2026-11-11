#include<bits/stdc++.h>
using namespace std;
int n,m;
int have[300005];
char a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        string desk="";
        for(int j=i;j<=n;j++){
            int pos=desk.find(a[j]);
            if(pos!=string::npos)
                desk.erase(pos,n-pos);
            desk=desk+a[j];
        }
        for(int j=1;j<=m;j++)
            if(desk.find(char(j+'0'))!=string::npos)
                have[j]++;
    }
    for(int i=1;i<=m;i++)
        cout<<have[i]<<" ";
}