#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long k=1;
    for(int i=1;i<=n;i++){
        int a;
        char b;
        cin>>a>>b;
        for(int j=k;j<=a+k;j++){
            s[j]=b;
        }
        k+=a;
    }
    long long sum=0;
    for(int i=1;i<=k/2;i++){
        if(s[i]!=s[k-i]){
            sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
