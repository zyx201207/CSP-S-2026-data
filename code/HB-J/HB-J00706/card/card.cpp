#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);


    long long n,m;
    long long a[10000001];
    bool b[10000001];
    vector<long long> c[m];
    vector<long long> ans[m];
    long long o=0;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<n;i++){


        for(long long j=i;j<n;j++){
            if(c[a[j]]>0){
                o=c[a[j]];
                for(int r=o;r<j;r++){
                    b[r]=false;
                }
                c[a[j]]=0;
            }
            c[a[j]]=j;
        }


        for(long long j=i;j<n;j++){
            if(b[j]){
                ans[a[j]]++;
            }
            else{
                b[j]=True;
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}