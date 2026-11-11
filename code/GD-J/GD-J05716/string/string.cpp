#include<bits/stdc++.h>
using namespace std;
int A[200000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,t=0;
    char b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        for(int j=t;j<t+a;j++){
            A[j]=b;
        }
        t+=a;
    }
    int ans=0;
    for(int i=0;i<=t/2;i++){
        if(A[i]!=A[t-i-1]){
            ans++;
        }
    }
    if(t%2==0){
        ans--;
    }
    cout<<ans;
    return 0;
}
