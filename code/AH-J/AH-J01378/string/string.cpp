#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,x,k=0;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>s;
        for(int j=1;j<=x;j++){
            a+=s;
        }
    }
    long long f=a.size()-1;
    if(f%2==0){
        f/=2;
    }else{
        f=f/2+1;
    }
    for(int i=0;i<=f;i++){
        if(a[i]!=a[a.size()-1-i]){
            k++;
        }
    }
    cout<<k;
    return 0;
}
