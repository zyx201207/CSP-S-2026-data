#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        b[i]=0;
    }
    long long m1=n,sum=0;
    while(m1){
        long long d[n];
        bool c[m+1];

        for(long long i=1;i<=m;i++){
            c[i]=false;
        }
        for(long long i=sum;i<n;i++){
            d[i]=a[i];
            for(long long j=sum;j<i;j++){
                if(d[j]==d[i]){
                    for(long long q=i;q>j;q--){
                        d[q]=0;
                    }
                }
            }
        }
        for(long long i=sum;i<n;i++){
            if(d[i]!=0&&!c[d[i]]){
                b[d[i]]++;
                c[d[i]]=true;
            }
        }
        sum++;
        m1--;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}