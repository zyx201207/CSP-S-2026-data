#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005],cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;

    cin>>n>>m;
    int l=n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        a[l]=a[i];
        if(b[a[i]]){
            if(a[b[a[i]]]!=a[i])b[a[i]]=l;
            l=b[a[i]];
        }
        else{
            b[a[i]]=l;
        }

        for(int j=l;j<=n;j++){
            cnt[a[j]]++;
            //cout<<a[j];
        }
        //cout<<'|';
        l--;
    }
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    //for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
}