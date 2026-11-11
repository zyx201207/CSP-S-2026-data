#include<bits/stdc++.h>
using namespace std;
char b[200005];
int a[200005];
int n;
string x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long l=0,r=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        r+=a[i];
        for(int j=1;j<=a[i];j++){
            x+=b[i];
        }
    }
    long long sum=0;
    while(l<r){
        if(x[l]!=x[r]){
        sum++;
        }
        l++;
        r--;
    }

    cout<<sum;
    return 0;
}
