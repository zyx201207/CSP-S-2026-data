#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector <long long> h(m+1);
    for(int i=1;i<=n;i++){
        int st[n+1],top=1;
        for(int j=i;j<=n;j++){
            for(int x=1;x<=top;x++){
                if(st[x]==a[j]){
                    top=x-1;
                    break;
                }
            }
            st[++top]=a[j];
        }
        for(int z=1;z<=top;z++)h[st[z]]++;
    }
    for(int i=1;i<=m;i++)cout<<h[i];
}
