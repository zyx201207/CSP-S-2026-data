#include<bits/stdc++.h>
using namespace std;

int main(){
    preopen(string.in,"r",stdin);
    preopen(string.out,"w",stdout);
    long long n,a,x=0,ans=0;
    char c,s[200005],sh[200005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        ans+=a;
        for(int j=0;j<a;j++){
            s[x]=c;
            x++;
        }
    }
    for(int i=ans-1,j=0;i>=0;i--,j++){
        sh[j]=s[i];
        if(s[j]==sh[j]){
            cout<<0;
            break;
    }

    return 0;
}
