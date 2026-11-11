#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    long long a,coun=0,h=1;
    char c,s[1000005]={};
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(long long j=h;j<h+a;j++){
            s[j]=c;
        }
        h+=a;
    }
    long long l=1,r=h-1;
    while(l<=r){
        if(s[l]!=s[r])coun++;
        l++;
        r--;
    }
    cout<<coun;

    return 0;
}
