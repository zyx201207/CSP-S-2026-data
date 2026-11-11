#include<iostream>
using namespace std;
string s,s2;
char c;
long long sum,n,a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a,&c);
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    long long len=s.size();
    for(long long i=len-1;i>=0;i--){
        s2+=s[i];
    }
    if(s2==s){
        cout<<0;
        return 0;
    }
    for(long long i=len-1;i>=0;i--){
        if(s[i]!=s2[i]){
            sum++;
            s[i]=s2[i];
            s2[len-i-1]=s[i];
        }
        if(s2==s){
            printf("%d",sum);
            return 0;
        }
    }
    return 0;
}

