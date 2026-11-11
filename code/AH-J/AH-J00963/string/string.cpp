#include<bits/stdc++.h>
using namespace std;
long long n,f;
long long x;
char c;
string s;
long long sum;
long long bl,bls;
int v[105];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        bl+=x;
        v[c]=1;
        if(x%2!=0){
            s+=c;
        }
        for(int j=1;j<=x/2;j++){
            s+=c;
            s+=c;
        }

    }
    int i=0,j=s.size()-1;
    if(s.size()%2==0){
        f=0;
    }else{
        f=1;
    }
    while(1){
        if(s[i]!=s[j]){
            sum++;
        }
        i++;
        j--;
        if(f==1&&i==s.size()/2&&j==s.size()/2)break;
        if(f==0&&i==s.size()/2-1&&j==s.size()/2)break;

    }
    if(s[i]!=s[j]){
        sum++;
    }
    printf("%lld",sum);


    return 0;
}




