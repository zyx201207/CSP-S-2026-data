#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m;
long long a[N];
long long jishu[N];
long long b[N];
long long kk;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            kk=b[j];
            for(int k=j+1;k<n;k++){
                if(kk!=0&&b[k]!=0&&kk==b[k]){
                    for(int l=j;l<=k;l++){
                        b[l]=0;
                    }
                }
            }
            for(int j=0;j<m;j++){
                jishu[b[j]]++;
            }
        }
    }
    for(int j=0;j<n;j++){
        cout<<jishu[j]<<" ";
    }
}


