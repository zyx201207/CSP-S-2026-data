#include <bits/stdc++.h>

using namespace std;

int a[500005],arr[500005],cnts[300005];
bool vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int pos=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]){
                pos--;
                while(arr[pos]!=a[j]){
                    vis[arr[pos--]]=false;
                }
            }
            arr[pos++]=a[j];
            vis[a[j]]=true;
        }
        for(int j=0;j<pos;j++){
            cnts[arr[j]]++;
            //cout<<arr[j]<<' ';
        }
        //cout<<'\n';
        for(int j=0;j<=m;j++){
            vis[j]=false;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnts[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
