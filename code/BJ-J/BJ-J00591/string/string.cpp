#include<bits/stdc++.h>
using namespace std;
int n;
int xxi=0,lsum;
char lnode;
long long len=0;
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>lsum>>lnode;
        len+=lsum;
        for(int j=1;j<=lsum;j++){
            str+=lnode;
        }
    }
    long long a,b;
    a=len/2;
    b=(len%2?len/2+1:len/2+2);
    long long ans1=0,ans2=0;
    for(int i=0;i<=a;i++){
        if(str[i]!=str[len-i-1])ans1++;
    }
    for(int i=b;i<len;i++){
        if(str[i]!=str[len-i-1])ans2++;
    }
    cout<<min(ans1,ans2);
    return 0;
}
