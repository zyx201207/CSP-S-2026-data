#include<bits/stdc++.h>
using namespace std;
string s,sold;long long num,sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        char b;
        scanf("%d %c",&a,&b);
        sum+=a;
        for(int j=0;j<a;j++)s+=b;
    }
    for(int i=sum-1;i>=0;i--){
        sold+=s[i];
    }
    for(int i=0;i<sum/2;i++){
        if(s[i]!=sold[i])num++;
    }
    cout<<num;
    return 0;
}