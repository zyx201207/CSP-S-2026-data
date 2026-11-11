#include<bits/stdc++.h>
using namespace std;
struct myc{
    int  a;
    char  b;
}s[100005];
char u[10000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
        int d=1;
        for(int j=d;j<=s[i].a;j++){
            u[j]=s[i].b;
        }
        d+=s[i].a;
        sum+=s[i].a;
    }
    int sum1=0;
    int lll=sum/2;
    for(int i=1;i<=lll;i++){
        if(u[i]!=u[lll-i+1]){
            sum1++;
        }
    }
    cout<<sum1;
    return 0;
}
