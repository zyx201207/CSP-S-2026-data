#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
map<int,int> z;
map<int,int> p;
int n,m,a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(NULL);
    cin.tie();
    cout.tie();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        z[a[i]]++;
        if(z[a[i]]==2){
            z[a[i]]=1;
            p[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<p[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
