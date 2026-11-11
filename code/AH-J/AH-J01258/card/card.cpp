#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[300010],l[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        if(l[a[i]]==0)l[a[i]]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ans[a[j]]++;
            //cout<<a[j]<<' ';
            if(l[a[j]]>j)j=l[a[j]];
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

