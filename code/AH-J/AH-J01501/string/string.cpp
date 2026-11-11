#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t=1,cnt=0;
    char c1[2000005],c2[2000005];
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        int p=t;
        for(int j=p;j<=p+a-1;j++){
            c1[j]=b;
            t=j+1;
        }
    }
    for(int i=1;i<t;i++){
        c2[t-i]=c1[i];
    }
    for(int i=1;i<t;i++){
        if(c1[i]!=c2[i]){
            c2[i]=c1[i];
            c1[t-i]=c2[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
