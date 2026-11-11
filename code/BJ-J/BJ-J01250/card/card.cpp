#include<bits/stdc++.h>
using namespace std;
long long a[300005];
long long x[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>x[i];
    }
    for(long long i=1;i<=n;i++){
        long long s[50005];
        long long s1[50005];
        long long s2[50005];
        long long k=1;
        for(long long j=1;j<=n;j++){
            s[j]=0;
            s1[j]=0;
            s2[j]=0;
        }
        for(long long j=i;j<=n;j++){
            if(s1[x[j]]==0){
                s[k]=x[j];
                s1[x[j]]=1;
                s2[x[j]]=k;
                k++;
            }else{
                int t=s2[x[j]];
                for(long long q=t;q<=k;q++){
                    s1[s[q]]=0;
                    s2[s[q]]=0;
                    s[q]=0;
                }
                k=t;
                s[k]=x[j];
                s1[x[j]]=1;
                s2[x[j]]=k;
                k++;
            }
        }
        for(long long j=1;j<k;j++){
            a[s[j]]++;
        }

    }
    for(long long j=1;j<=m;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}
