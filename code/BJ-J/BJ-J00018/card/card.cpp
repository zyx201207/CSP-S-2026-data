/*#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    int ans[m];
    for(int i=0;i<m;i++)ans[i]=0;
    for(long long i=0;i<n;i++){
        int b[n+1];
        for(int j=0;j<n;j++)b[j]=0;
        for(long long j=i+1;j<n;j++){
            b[j]=a[j];
            for(long long k=j-1;k>=0;k--){
                if(b[j]==b[k]){
                    for(long long l=k;k<j-1;k++){
                        b[k]=0;
                    }
                }
            }
            //cout<<b[i]<<" ";
        }
        for(int j=0;j<n;j++){
            if(b[j]!=0)ans[b[j]]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
}
*/

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    long long ans[m];
    for(long long i=0;i<m;i++)ans[i]=0;
    for(long long i=0;i<n;i++){
        long long b[n];
        for(long long j=0;j<n;j++)b[j]=0;
        for(long long j=i;j<n;j++){
            b[j]=a[j];
            //cout<<b[j]<<" ";
            for(long long k=j;k>=0;k--){
                if(b[j]==b[k]){
                    for(long long l=k;l<j;l++){
                        b[l]=0;
                    }
                    break;
                }
            }
        }
        //cout<<endl;
        for(long long j=i+1;j<n;j++){
            if(b[j]!=0)ans[b[j]-1]++;
            //cout<<b[j]<<" ";
        }
       // cout<<endl;
    }
    for(long long i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
}

