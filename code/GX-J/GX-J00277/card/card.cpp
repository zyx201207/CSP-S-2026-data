#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n],b[n],s[m+1];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<n;j++){
            for(long long c=0;c<=n-i;c++){
                b[c]=a[j];
                for(long long f=0;f<=c;f++){
                    if(b[f]==b[c]){
                        for(long long k=f;k<c;k++){
                            b[k]=0;
                        }
                        b[f]=b[c];
                        b[c]=0;
                    }
                }
            }
        }
        for(long long j=1;j<=m;j++){
                for(long long t=0;t<n;t++){
                    if(b[t]==j){
                        s[j]++;
                    }
            }
        }
        for(int j=0;j<n;j++){
            b[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
