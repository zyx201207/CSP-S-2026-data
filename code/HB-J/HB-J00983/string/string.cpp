#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c=0,s,p;
    long long a,q[200001],j,o;
    char d[200001],b;
    cin>>n;
    j=n;
    for(long long i=0;i<n;i++){
        cin>>q[i];
        cin>>d[i];
        j+=q[i];
    }
    s=0;
    p=n-1;
    for(long long i=0;i<j/2;i++){
        if(q[p]==0){
            p--;
        }else if(q[s]==0){
            s++;
        }
        if(d[s]==d[p]){
            if(q[s]>=q[p]){
                q[s]=q[s]-q[p];
                p--;
            }else if(q[s]<q[p]){
                q[p]=q[p]-q[s];
                s++;
            }
        }else {
            if(q[s]>=q[p]){
                q[s]=q[s]-q[p];
                o+=q[p];
                p--;

            }else if(q[s]<q[p]){
                q[p]=q[p]-q[s];
                o+=q[s];
                s++;
            }
        }
        if(s==p){
           i=j/2;
        }
    }
    cout<<o;
    return 0;
}
