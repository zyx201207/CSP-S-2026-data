#include<bits/stdc++.h>
using namespace std;
int a[500020];
int b[500020];
int k[300020];
int mi[300020];
map<int,map<int,int> > mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]][++mi[a[i]]]=i;
        b[i]=mi[a[i]];

    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(mp[a[j]][b[j]+1]<1){
                k[a[j]]++;
                j++;
                continue;
            }

            j=mp[a[j]][b[j]+1];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<k[i];
        if(a[i]!=n){
            printf(" ");
        }
    }

    fclose(stdin);fclose(stdout);
    return 0;
}
