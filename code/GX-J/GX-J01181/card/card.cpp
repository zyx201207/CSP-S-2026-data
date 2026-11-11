#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in",stin);
    freopen("card.ans",stout);
    long long m,n,l=0;
    cin>>n>>m;
    long long a[n],b[3];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    l=j;
                }
            }
        }
        for(int i=l;i<n;i++){
            b[a[i]-1]+=1;
        }
    }
    for(int i=0;i<3;i++){
        if(b[i]!=0){
            cout<<b[i];
        }
    }
    return 0;
}
