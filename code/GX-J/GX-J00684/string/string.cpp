#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,e=0,l,ans=0;
    char b;
    string m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int j=0;j<a;j++){
            m=m+b;
            ans++;
        }
    }
    for(int l=0;l<ans;l++){
        if(m[l]==m[ans]){
            e=e;
        }
        else{
            e++;
        }
        ans--;
    }
    cout<<e;
    return 0;
}
