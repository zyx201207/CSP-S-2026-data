#include<bits/stdc++.h>
using namespace std;
int s[10000001];
int check(int n){
    int l=1,r=n,num=0;
    while(l<=(n/2) && r>=(n/2)){
        if(s[l]!=s[r]){
            num++;
        }
    }
    return num;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    int a[n+1];
    char c[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s[sum+j]=c[i]-'a';
        }
        sum+=a[i];
    }
    cout<<check(sum);
    return 0;
}

