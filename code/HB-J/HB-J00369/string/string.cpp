#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200005]={};
    char c[200005]={};
    string s="";
    ll cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
        cnt+=a[i];
    }
    ll sum=0;
    for(ll i=0;i<cnt/2;i++){
        if(s[i]!=s[cnt-i-1])sum++;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
