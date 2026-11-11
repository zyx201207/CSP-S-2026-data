#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,num=0,sum=0;
    char c;
    string b={},p;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int i=1;i<=a;i++)
            b+=c;
        sum+=a;
    }
    p=b;
    for(int i=0;i*i<=sum;i++){
        if(p[i]!=p[sum-i-1]){
            num++;
        }
    }
    cout<<num;
    return 0;
}
