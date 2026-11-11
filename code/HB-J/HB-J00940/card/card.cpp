#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500000],x,ans[500000],l,k;
    cin>>n>>m;
    l=n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int q=0;q<n;q++){
        for(int i=0;i<l;i++){
            k=0;
            for(int j=i+1;j<l;j++){
                if(a[i]==a[j])k=1;
                for(int y=0;y<i;y++){
                    if(a[j]==a[y])k=1;
                }
            }
            if(k==0)ans[a[i]]++;
        }
        for(int i=0;i<l;i++)a[i]=a[i+1];
        l-=1;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
