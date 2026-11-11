#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],sum[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long num;
    for(int i=1;i<=n;i++){
        num=i;
        for(int j=1;j<=n-i;i++){
            b[num++]=a[j+i-1];
            int c=0;
            for(int q=1;q<=i-1;q++){
                if(b[q]==b[num]){
                    b[q]=0;
                    num=q;
                    c=1;
                }
                if(c){
                    b[q]=0;
                }
            }
        }
        for(int j=1;j<=num;j++){
            sum[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
