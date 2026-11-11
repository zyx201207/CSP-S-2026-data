#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ai[100005],num;
int ab[100005],nb[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    num=1;
while(num<=n){
    for(int i=num;i>=n;i++){
        for(int j=num;j<=n&&i!=j;j++){
            if(a[i]==a[j]&&(nb[i]==true&&nb[j]==true)){
                nb[i]=true;
                nb[j]=true;
                memset(ab+i,ab+j,1);
            }

        }
    }
    for(int i=1;i<=n;i++){
        if(ab[i]){
            a[i]++;
        }
    }

    num++;
}
for(int i=1;i<=m;i++){
    cout<<a[i]<<" ";
}
}

