#include<bits/stdc++.h>
using namespace std;
bool pd(string a){
    string b;
    for(int i=a.size()-1;i>=0;i--){
        b+=a[i];
    }
    return a==b;
}
int main(){
    freopen("string.int","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a,b;
    char z;
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>z;
        while(k--){
            a+=z;
        }
        b+=z;
    }
    int cnt=0;
    if(pd(a)){
        cout<<0;
    }else{
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();i++){
                a[i]=b[j];
                if(pd(a)) cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
